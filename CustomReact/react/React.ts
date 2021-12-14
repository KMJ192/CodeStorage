import debounceFrame from './debounceFrame/debounceFrame';

function React() {
  const _this = {
    currStateKey: 0,
    states: [],
    component: null,
    root: null,
    renderingCount: 0,
  };

  function render(inputComponent: () => any, rootEle: Element | null) {
    _this.component = inputComponent;
    _this.root = rootEle;
    reactRenderer();
  }

  const reactRenderer = debounceFrame(() => {
    const { root, component } = _this;
    if (root === null || component === null) return;
    root.innerHTML = `
      <div>${_this.renderingCount}</div>
      ${component()}
    `;
    _this.currStateKey = 0;
  });

  function useState<T = undefined>(initState: T): [T, (newVal: T) => void] {
    const { states, currStateKey } = _this;

    const state = states[currStateKey] || initState;
    const _currStateKey = currStateKey;

    const setState = (newState: T) => {
      if (newState === state) return;
      // map set과 같은 원시타입은 비교하지 걸러내지 못하므로 로직이 추가로 필요함...
      if (JSON.stringify(newState) === JSON.stringify(state)) return;

      states[_currStateKey] = newState;
      _this.renderingCount++;
      reactRenderer();
    };

    _this.currStateKey++;
    return [state, setState];
  }

  function useEffect(callback: () => any, depArray?: any[]) {
    const { states, currStateKey } = _this;
    const hasNoDeps = !depArray;
    const deps = states[currStateKey];
    console.log(currStateKey);
    const hasChangedDeps: boolean = deps
      ? !depArray?.every((el: any, i: number) => el === deps[i])
      : true;
    if (hasNoDeps || hasChangedDeps) {
      callback();
      states[currStateKey] = depArray;
    }
    _this.currStateKey++;
  }

  // virtual dom을 생성하는 코드
  function createElement() {}

  return {
    useState,
    useEffect,
    render,
  };
}

export default React;
