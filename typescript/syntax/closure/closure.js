"use strict";
exports.__esModule = true;
exports.closureFunc = void 0;
function classClosure() {
    var fn = "classClosure";
    return /** @class */ (function () {
        function class_1(name, pw) {
            this.name = "some";
            this.pw = "1234";
            this.name = name;
            this.pw = pw;
        }
        class_1.prototype.display = function () {
            console.log("user : " + this.name + ", pw : " + this.pw + ", fn : " + fn);
        };
        class_1.prototype.rtThis = function () {
            return {
                name: this.name,
                pw: this.pw,
                fn: fn
            };
        };
        return class_1;
    }());
}
var global = (function () {
    var innerText = "innerText";
    function examOne() {
        var setText = function (cText) {
            innerText = cText;
        };
        return [innerText, setText];
    }
    return {
        examOne: examOne
    };
})();
var Test = /** @class */ (function () {
    function Test(tmp) {
        this.test = "";
        this.test = tmp;
    }
    Test.prototype.display = function () {
        console.log(this.test);
    };
    return Test;
}());
function closureFunc() {
    var tmp = classClosure();
    console.log(tmp);
    var test = new Test("123");
    test.display();
}
exports.closureFunc = closureFunc;
