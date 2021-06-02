"use strict";
exports.__esModule = true;
exports.closureFunc = void 0;
function examOne() {
    var innerText = "내부값";
    return {
        setText: function (cText) {
            innerText = cText;
        },
        getText: function () {
            console.log(innerText);
        }
    };
}
function closureFunc() {
    var test1 = examOne();
    var test2 = examOne();
    var test3 = examOne();
    test1.getText();
    test2.getText();
    test3.getText();
    test1.setText("test2");
    test2.setText("test4");
    test3.setText("test6");
    test1.getText();
    test2.getText();
    test3.getText();
}
exports.closureFunc = closureFunc;
