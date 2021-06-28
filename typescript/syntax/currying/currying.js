"use strict";
var __spreadArray = (this && this.__spreadArray) || function (to, from) {
    for (var i = 0, il = from.length, j = to.length; i < il; i++, j++)
        to[j] = from[i];
    return to;
};
exports.__esModule = true;
exports.curryingRun = void 0;
var examObject = {
    first: "first",
    second: "second"
};
function examFunc() {
    var arg = [];
    for (var _i = 0; _i < arguments.length; _i++) {
        arg[_i] = arguments[_i];
    }
    var arr = [this.first, this.second];
    var outputArr = arr.concat(arg);
    console.log("" + outputArr);
}
Function.prototype.myBinding = function () {
    var args = [];
    for (var _i = 0; _i < arguments.length; _i++) {
        args[_i] = arguments[_i];
    }
    var obj = this; // 여기서 this는 examFunc이 된다.
    var rest = args.slice(1);
    return function () {
        var args2 = [];
        for (var _i = 0; _i < arguments.length; _i++) {
            args2[_i] = arguments[_i];
        }
        obj.apply(args[0], __spreadArray(__spreadArray([], rest), args2));
    };
};
function mulNum(arg) {
    console.log(this);
    var val = 1;
    for (var i = 0; i < arg.length; i++) {
        val *= arg[i];
    }
    console.log(val);
}
function addNum(arg) {
    var val = 0;
    for (var i = 0; i < arg.length; i++) {
        val += arg[i];
    }
    console.log(val);
}
function currying(fn) {
    var arg = [];
    for (var _i = 1; _i < arguments.length; _i++) {
        arg[_i - 1] = arguments[_i];
    }
    return function () {
        fn(arg);
    };
}
function curryingRun() {
    // const tmp = examFunc.myBinding(examObject, "third", "forth", "fifth");
    // tmp("sixth", "seventh");
    var mul = currying(mulNum, 1, 2, 3, 4, 5);
    var add = currying(addNum, 1, 2, 3, 4, 5, 6);
    mul();
    add();
}
exports.curryingRun = curryingRun;
