"use strict";
exports.__esModule = true;
exports.thisRun = void 0;
var object = {
    name: "name",
    whoami: function () {
        console.log(this);
    }
};
function thisRun() {
    //object의 this를 출력
    object.whoami();
    //현재 scope(thisRun 함수)의 this를 출력
    var who = object.whoami;
    who();
}
exports.thisRun = thisRun;
function onclickEvent() {
    var object = {
        name: "name",
        whoami: function () {
            console.log(this);
        }
    };
    object.whoami();
    var who = object.whoami;
    who();
}
