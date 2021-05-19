"use strict";
exports.__esModule = true;
exports.climbStairs = void 0;
function climbStairs(n) {
    if (n === 0)
        return 0;
    if (n === 1)
        return 1;
    if (n === 2)
        return 2;
    var tmp1 = 1;
    var tmp2 = 2;
    var answer = 0;
    for (var i = 2; i < n; i++) {
        answer = tmp1 + tmp2;
        tmp1 = tmp2;
        tmp2 = answer;
    }
    console.log(answer);
    return answer;
}
exports.climbStairs = climbStairs;
;
