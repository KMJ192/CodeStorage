// function useState<T>(initVal: T): [() => T, (newVal: T) => void]{
//     let _val: T = initVal;
//     const state = () => _val;
//     const setState = (newVal: T) => {
//         _val = newVal;
//     }
//     return [state, setState];
// }

const React = (function() {
    let hooks: any = [];
    let currentHook: number = 0;
    function useState<T>(initVal: T): [T, (newVal: T) => void]{
        const state = hooks[currentHook] || initVal;
        const _currentHook = currentHook;
        const setState = (newVal: T) => {
            hooks[_currentHook] = newVal;
        }
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
        useState,
        hooks
        //useEffect
    };
})();

export function run(){
    const [count, setCount] = React.useState<number>(1);
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

//inheritance prototype closure call apply bind currying