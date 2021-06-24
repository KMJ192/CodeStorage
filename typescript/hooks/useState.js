"use strict";
// function useState<T>(initVal: T): [() => T, (newVal: T) => void]{
//     let _val: T = initVal;
//     const state = () => _val;
//     const setState = (newVal: T) => {
//         _val = newVal;
//     }
//     return [state, setState];
// }
exports.__esModule = true;
exports.run = void 0;
var React = (function () {
    var hooks = [];
    var currentHook = 0;
    function useState(initVal) {
        var state = hooks[currentHook] || initVal;
        var _currentHook = currentHook;
        var setState = function (newVal) {
            hooks[_currentHook] = newVal;
        };
        currentHook++;
        return [state, setState];
    }
    // function useEffect(callback: Function, depArray?: any[]){
    //     const hasNoDeps = !depArray;
    //     const deps = hooks[currentHook];
    //     const hasChangedDeps = deps
    //         ? !depArray?.every((el: any, i: number) => el === deps[i]) : true;
    //     if(hasNoDeps || hasChangedDeps){
    //         callback()
    //         hooks[currentHook] = depArray;
    //     }
    //     currentHook++;
    // }
    return {
        useState: useState,
        hooks: hooks
        //useEffect
    };
})();
function run() {
    var _a = React.useState(1), count = _a[0], setCount = _a[1];
    setCount(2);
    console.log(count);
    //setCount2(3);
    //setCount(2);
    //console.log(count);
    //console.log(React.hooks);
    // setCount(4);
    // console.log(count);
    // setCount(5);
    // console.log(count);
}
exports.run = run;
//inheritance prototype closure call apply bind currying pollyfill
