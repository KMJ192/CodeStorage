"use strict";
exports.__esModule = true;
exports.run = void 0;
var React = (function () {
    var hooks = [];
    var currentHook = 0;
    function useState(initVal) {
        var state = hooks[currentHook] || initVal;
        var _currentHook = currentHook; //상태에 대한 배열의 index를 고정해둔다.
        var setState = function (newVal) {
            hooks[_currentHook] = newVal; //고정한 index에  값을 집어 넣는다.
        };
        currentHook++; //어떤 state가 설정 되었을때 다음 state가 설정될 경우를 위해 index를 1증가시켜 둔다.
        return [state, setState];
    }
    function useEffect(callback, depArray) {
        //deps배열에 바뀐 내용이 있는지 검증
        var hasNoDeps = !depArray;
        var deps = hooks[currentHook];
        var hasChangedDeps = deps ? !(depArray === null || depArray === void 0 ? void 0 : depArray.every(function (el, i) { return el === deps[i]; })) : true;
        if (hasNoDeps || hasChangedDeps) {
            //바뀐 내용이 있다면 첫번째 parameter로 받아온 callback함수를 실행한다.
            callback();
            hooks[currentHook] = depArray;
        }
        currentHook++;
    }
    function render(Component) {
        currentHook = 0;
        var C = Component();
        //컴포넌트의 render함수(closure)를 실행하여 React 함수 전체를 업데이트한다.
        //useState로 설정해 둔 각각의 state별로 React App 전체를 업데이트 하여 상태가 연동되도록 한다.
        C.render();
        return C;
    }
    return {
        useState: useState,
        useEffect: useEffect,
        render: render
    };
})();
function Component() {
    var _a = React.useState(1), count = _a[0], setCount = _a[1];
    var _b = React.useState("초기값"), text = _b[0], setText = _b[1];
    React.useEffect(function () {
        console.log("increase count " + count);
        console.log("\uD14D\uC2A4\uD2B8 \"" + text + "\"");
    }, [count, text]);
    return {
        render: function () {
            console.log("컴포넌트를 렌더링 합니다.");
        },
        click: function () { return setCount(count + 1); },
        setString: function (newVal) { return setText(newVal); }
    };
}
function run() {
    var App = React.render(Component);
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
exports.run = run;
//inheritance prototype closure call apply bind currying pollyfill
