export function EventLoop(){
    setTimeout(() => {
        console.log("2s")
    }, 2000);

    setTimeout(() => {
        console.log("1s")
    }, 1000);

    setTimeout(() => {
        console.log("3s")
    }, 3000);

    setTimeout(() => {
        console.log("0s")
    }, 0);

    // Promise.resolve().then(() => {
    //     console.log("Promise");
    // });
    console.log("start");
}