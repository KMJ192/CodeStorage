"use strict";
exports.__esModule = true;
var currying_1 = require("./syntax/currying/currying");
function main() {
    currying_1.curryingRun();
}
main();
function eTest() {
    var array = ["1", "2", "3", "4"];
    var array1 = ["1", "2", "3", "4"];
    var tmp = array.some(function (el, i) { return el === array1[i]; });
    console.log(tmp);
}
//eTest();
