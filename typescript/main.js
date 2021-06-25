"use strict";
exports.__esModule = true;
var async_await_1 = require("./syntax/async/async_await/async_await");
function main() {
    async_await_1.AsyncAwait();
}
main();
function eTest() {
    var array = ["1", "2", "3", "4"];
    var array1 = ["1", "2", "3", "4"];
    var tmp = array.some(function (el, i) { return el === array1[i]; });
    console.log(tmp);
}
//eTest();
