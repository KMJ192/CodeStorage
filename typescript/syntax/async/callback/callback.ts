function callbackRun(callback: Function, num: number){
    callback();
    console.log(num);
}

export function callbackFu(){
    setTimeout(() => {
        console.log("asyncronous");
    }, 0);

    callbackRun(() => {
        callbackRun(() => {
            callbackRun(() => {
                callbackRun(() => {
                    callbackRun(() => {
                        console.log("last deps");
                    }, 5)
                }, 4)
            }, 3)
        }, 2)
    }, 1)
    callbackRun(() => {}, 0);

    console.log("first deps");
}

