"use strict";
exports.__esModule = true;
exports.isValid = void 0;
function isValid(s) {
    var st = [];
    var brackets = {
        '(': ')',
        '{': '}',
        '[': ']'
    };
    for (var i = 0; i < s.length; i++) {
        if (s[i] === '(' || s[i] === '{' || s[i] === '[')
            st.push(s[i]);
        else if (brackets[st.pop()] !== s[i])
            return false;
    }
    return true;
}
exports.isValid = isValid;
