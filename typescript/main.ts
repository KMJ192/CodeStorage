import { AsyncAwait } from "./syntax/async/async_await/async_await";

function main(){
    AsyncAwait();
}
main();


function eTest(){
    let array: string[] = ["1", "2", "3", "4"];
    let array1: string[] = ["1", "2", "3", "4"];
    let tmp = array.some((el: string, i: number) => el === array1[i]);
    console.log(tmp);
}

//eTest();
