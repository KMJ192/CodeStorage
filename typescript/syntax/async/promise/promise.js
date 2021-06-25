"use strict";
exports.__esModule = true;
exports.promiseRun = void 0;
function example() {
    return new Promise(function (resolve, reject) {
        try {
            setTimeout(function () {
                resolve(1);
            }, 1000);
        }
        catch (e) {
            reject(e);
        }
    });
}
function promiseRun() {
    example()
        .then(function (value) { return value + value; })
        .then(function (value) { return value + value; })
        .then(function (value) { return console.log(value); })["catch"](function (error) { return console.log(error); });
}
exports.promiseRun = promiseRun;
