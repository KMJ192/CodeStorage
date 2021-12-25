const React = (function () {
  let hooks: any = [];
  let currentHook: number = 0;

  function useState<T>(initVal: T): [T, (newVal: T) => void] {
    const state = hooks[currentHook] || initVal;
    const _currentHook = currentHook; //상태에 대한 배열의 index를 고정해둔다.
    const setState = (newVal: T) => {
      hooks[_currentHook] = newVal; //고정한 index에  값을 집어 넣는다.
    };
    currentHook++; //어떤 state가 설정 되었을때 다음 state가 설정될 경우를 위해 index를 1증가시켜 둔다.
    return [state, setState];
  }

  function useEffect(callback: Function, depArray?: any[]) {
    //deps배열에 바뀐 내용이 있는지 검증
    const hasNoDeps: boolean = !depArray;
    const deps = hooks[currentHook];
    const hasChangedDeps: boolean = deps
      ? !depArray?.every((el: any, i: number) => el === deps[i])
      : true;
    if (hasNoDeps || hasChangedDeps) {
      //바뀐 내용이 있다면 첫번째 parameter로 받아온 callback함수를 실행한다.
      callback();
      hooks[currentHook] = depArray;
    }
    currentHook++;
  }

  function render(Component: Function) {
    currentHook = 0;
    const C = Component();
    //컴포넌트의 render함수(closure)를 실행하여 React 함수 전체를 업데이트한다.
    //useState로 설정해 둔 각각의 state별로 React App 전체를 업데이트 하여 상태가 연동되도록 한다.
    C.render();
    return C;
  }

  return {
    useState,
    useEffect,
    render,
  };
})();

function Component() {
  const [count, setCount] = React.useState<number>(1);
  const [text, setText] = React.useState<string>("초기값");

  React.useEffect(() => {
    console.log(`increase count ${count}`);
    console.log(`텍스트 "${text}"`);
  }, [count, text]);

  return {
    render: () => {
      console.log("컴포넌트를 렌더링 합니다.");
    },
    click: () => setCount(count + 1),
    setString: (newVal: string) => setText(newVal),
  };
}

export function HooksTest() {
  let App = React.render(Component);
  App.click();
  App.setString("바뀐값1");
  App = React.render(Component);
  App.click();
  App.setString("바뀐값2");
  App = React.render(Component);
  App.click();
  App.setString("바뀐값3");
  App = React.render(Component);
}

//inheritance prototype closure call apply bind currying pollyfill
