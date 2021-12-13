import debounceFrame from './debounceFrame/debounceFrame';

function React() {
  const _this = {
    currStateKey: 0,
    states: [],
    component: null,
    root: null,
  };

  function render(inputComponent: () => any, rootEle: Element | null) {
    _this.component = inputComponent;
    _this.root = rootEle;
    reactRenderer();
  }

  const reactRenderer = debounceFrame(() => {
    const { root, component } = _this;
    if (root === null || component === null) return;
    root.innerHTML = component();
    _this.currStateKey = 0;
  });

  function useState<T = undefined>(initState: T): [T, (newVal: T) => void] {
    const { states, currStateKey } = _this;

    const state = states[currStateKey] || initState;
    const _currStateKey = currStateKey;

    const setState = (newState: T) => {
      if (newState === state) return;
      if (JSON.stringify(newState) === JSON.stringify(state)) return;

      states[_currStateKey] = newState;
      reactRenderer();
    };

    _this.currStateKey++;
    return [state, setState];
  }

  function useEffect(callback: () => any, depArray?: any[]) {
    const { states, currStateKey } = _this;
    const hasNoDeps = !depArray;
    const deps = states[currStateKey];
    const hasChangedDeps: boolean = deps
      ? !depArray?.every((el: any, i: number) => el === deps[i])
      : true;
    if (hasNoDeps || hasChangedDeps) {
      callback();
      states[currStateKey] = depArray;
    }
    _this.currStateKey++;
  }

  return {
    useState,
    useEffect,
    render,
  };
}

export default React;
