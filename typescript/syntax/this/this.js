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
    var arg = [];
    for (var _i = 0; _i < arguments.length; _i++) {
        arg[_i] = arguments[_i];
    }
    this.name = "" + arg[0];
    this.pw = "" + arg[1];
}
function callTest() {
    var arg = [];
    for (var _i = 0; _i < arguments.length; _i++) {
        arg[_i] = arguments[_i];
    }
    console.log(this.name);
    console.log(this.pw);
    console.log("call binding name : " + arg[0] + ", pw : " + arg[1]);
    //console.log(test);
}
function applyTest(test1, test2) {
    console.log(this.name + ", " + this.pw);
    console.log(test1);
    console.log(test2);
}
var Temp = /** @class */ (function () {
    function Temp() {
        this.str = "";
    }
    Temp.prototype.setStr = function (data) {
        this.str = data;
    };
    Temp.prototype.print = function () {
        console.log("this " + this);
        console.log("Temp's data: " + this.str);
    };
    return Temp;
}());
function thisRun() {
    //암시적 바인딩 => this는 this가 속해있는 Object를 가리킨다.
    //object.whoami();
    //암시적 소실 => this는 window를 가리킨다. (script mode => undefined)
    //thisTest(object.whoami);
    // new => 함수를 객체로 만들어 준다. this는 해당 객체를 가리킨다.
    // let newBinding = new bindTest("name", "pw");
    // console.log(`${newBinding.name}, ${newBinding.pw}`);
    // call/apply binding => 첫번째 arg로 함수를 넣어주며 주번째 인자값은 해당 함수가 받을 parameter
    // this는 첫번째 arg로 넘겨준 함수를 가리킨다.
    // callTest.call(newBinding, "test", "123");
    // applyTest.apply(bindTest, ["arg1", "arg2"]);
    var bObject = {
        name: 'name',
        pw: '12'
    };
    var bTest = callTest.bind(bObject, "123", "456");
    bTest.args = {
        name: 'name2',
        pw: '123'
    };
    bTest();
    // let tmp = new Temp;
    // tmp.setStr("123");
    // tmp.print();
}
exports.thisRun = thisRun;
