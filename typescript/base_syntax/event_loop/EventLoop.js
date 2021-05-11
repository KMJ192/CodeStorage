"use strict";
exports.__esModule = true;
exports.EventLoop = void 0;
function EventLoop() {
    setTimeout(function () {
        console.log("2s");
    }, 2000);
    setTimeout(function () {
        console.log("1s");
    }, 1000);
    setTimeout(function () {
        console.log("3s");
    }, 3000);
    setTimeout(function () {
        console.log("0s");
    }, 0);
    Promise.resolve().then(function () {
        console.log("Promise");
    });
    console.log("start");
}
exports.EventLoop = EventLoop;
