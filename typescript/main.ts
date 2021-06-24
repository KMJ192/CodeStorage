//import { run } from "./base_ds_algorithm/divide_and_conquer/merge_sort";
import { run } from './hooks/useState';
import { closureFunc } from './syntax/closure/closure';
import { thisRun } from './syntax/this/this';

function main(){
    run();
    //closureFunc();
    //thisRun();
}
main();


function eTest(){
    let array: string[] = ["1", "2", "3", "4"];
    let array1: string[] = ["1", "2", "3", "4"];
    let tmp = array.some((el: string, i: number) => el === array1[i]);
    console.log(tmp);
}

//eTest();
