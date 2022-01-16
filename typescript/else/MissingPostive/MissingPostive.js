"use strict";
exports.__esModule = true;
function solution(input, k) {
    var answer = Array.from({ length: k }, function () { return 0; });
    input.sort(function (a, b) { return b - a; });
    console.log(input);
    return answer;
}
function run() {
    var input = [3, -1, 4, 5, 5];
    solution(input, 3);
}
exports["default"] = run;
