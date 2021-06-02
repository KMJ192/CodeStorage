import { thisRun } from "./syntax/this/this";
import { asyncProcess } from "./syntax/async/asyncExam";
import { closureFunc } from "./syntax/closure/closure";

function main(){
    //asyncProcess();
    //closureFunc();
    thisRun();
}
//main();

function test(){
    const b = "b";
    const obj = {
        a : "a",
        b : () => {
            console.log(this);
        }
    }
    obj.b();
}

test();