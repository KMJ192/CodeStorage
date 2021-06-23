"use strict";
exports.__esModule = true;
exports.closureFunc = void 0;
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
function closureFunc() {
    var _a = global.examOne(), state = _a[0], setText = _a[1];
    setText("2");
    console.log(state);
}
exports.closureFunc = closureFunc;
