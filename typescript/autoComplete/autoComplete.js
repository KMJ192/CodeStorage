"use strict";
exports.__esModule = true;
function autoComplete() {
    var tmp = new Set();
    tmp.add("app");
    tmp.add("apple");
    tmp.add("append");
    tmp.add("한");
    tmp.add("한글");
    tmp.add("한글 자동완성");
    tmp.forEach(function (value) {
        console.log(value);
    });
}
exports["default"] = autoComplete;
