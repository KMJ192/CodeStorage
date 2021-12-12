import debounceFrame from "../debounceFrame/debounceFrame";

function React() {
  const _this = {
    currStateKey: 0,
    states: [],
    component: null,
    root: null,
  };

  function render(inputComponent: Function, rootEle: Element | null) {
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

  function useEffect(callback: Function, depArray?: any[]) {
    const { states, currStateKey } = _this;
    //deps배열에 바뀐 내용이 있는지 검증
    const hasNoDeps: boolean = !depArray;
    const deps = states[currStateKey];
    const hasChangedDeps: boolean = deps
      ? !depArray?.every((el: any, i: number) => el === deps[i])
      : true;
    if (hasNoDeps || hasChangedDeps) {
      //바뀐 내용이 있다면 첫번째 parameter로 받아온 callback함수를 실행한다.
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
