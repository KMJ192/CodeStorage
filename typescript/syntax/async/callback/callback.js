"use strict";
exports.__esModule = true;
exports.callbackFu = void 0;
function callbackRun(callback, num) {
    callback();
    console.log(num);
}
function callbackFu() {
    _sampleCode(function () {
        console.log("asyncronous");
    }, 0);
    callbackRun(function () {
        callbackRun(function () {
            callbackRun(function () {
                callbackRun(function () {
                    callbackRun(function () {
                        console.log("last deps");
                    }, 5);
                }, 4);
            }, 3);
        }, 2);
    }, 1);
    callbackRun(function () { }, 0);
    console.log("first deps");
}
exports.callbackFu = callbackFu;
