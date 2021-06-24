"use strict";
exports.__esModule = true;
//import { run } from "./base_ds_algorithm/divide_and_conquer/merge_sort";
var useState_1 = require("./hooks/useState");
function main() {
    useState_1.run();
    //closureFunc();
    //thisRun();
}
main();
function eTest() {
    var array = ["1", "2", "3", "4"];
    var array1 = ["1", "2", "3", "4"];
    var tmp = array.some(function (el, i) { return el === array1[i]; });
    console.log(tmp);
}
//eTest();
