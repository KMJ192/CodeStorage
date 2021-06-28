"use strict";
exports.__esModule = true;
var this_1 = require("./syntax/this/this");
function main() {
    //curryingRun();
    this_1.thisRun();
}
main();
function eTest() {
    var array = ["1", "2", "3", "4"];
    var array1 = ["1", "2", "3", "4"];
    var tmp = array.some(function (el, i) { return el === array1[i]; });
    console.log(tmp);
}
//eTest();
