"use strict";
var __spreadArrays = (this && this.__spreadArrays) || function () {
    for (var s = 0, i = 0, il = arguments.length; i < il; i++) s += arguments[i].length;
    for (var r = Array(s), k = 0, i = 0; i < il; i++)
        for (var a = arguments[i], j = 0, jl = a.length; j < jl; j++, k++)
            r[k] = a[j];
    return r;
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
        obj.apply(args[0], __spreadArrays(rest, args2));
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
