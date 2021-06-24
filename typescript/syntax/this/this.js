"use strict";
exports.__esModule = true;
exports.thisRun = void 0;
var object = {
    name: "OBJ",
    whoami: function () {
        var _this = this;
        console.log(this);
        var thisTest = function () {
            console.log(_this);
        };
        thisTest();
    }
};
function thisTest(test) {
    test();
}
function bindTest() {
    this.name = "bindTest";
    this.pw = "123";
}
function callTest(test) {
    console.log("call binding this.name : " + this.name + ", this.pw : " + this.pw);
    console.log(test);
}
function applyTest(test1, test2) {
    console.log(this.name + ", " + this.pw);
    console.log(test1);
    console.log(test2);
}
function thisRun() {
    //암시적 바인딩 => this는 this가 속해있는 Object를 가리킨다.
    object.whoami();
    //암시적 소실 => this는 window를 가리킨다. (script mode => undefined)
    thisTest(object.whoami);
    // new => 함수를 객체로 만들어 준다. this는 해당 객체를 가리킨다.
    var newBinding = new bindTest();
    console.log(newBinding.name + ", " + newBinding.pw);
    // call binding
    callTest.call(bindTest, "test");
    // apply binding
    applyTest.apply(bindTest, ["arg1", "arg2"]);
}
exports.thisRun = thisRun;
