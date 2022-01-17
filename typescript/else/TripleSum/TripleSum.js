"use strict";
var __assign = (this && this.__assign) || function () {
    __assign = Object.assign || function(t) {
        for (var s, i = 1, n = arguments.length; i < n; i++) {
            s = arguments[i];
            for (var p in s) if (Object.prototype.hasOwnProperty.call(s, p))
                t[p] = s[p];
        }
        return t;
    };
    return __assign.apply(this, arguments);
};
exports.__esModule = true;
var Solution = /** @class */ (function () {
    function Solution(input, target) {
        this.input = input;
        this.target = target;
        this.closetValue = [0, 0, 0];
        this.closet = 0;
        this.returnValue = -1;
    }
    Solution.prototype.renewal = function (index) {
        var first = index.first, second = index.second, third = index.third;
        this.closetValue[0] = this.input[first];
        this.closetValue[1] = this.input[second];
        this.closetValue[2] = this.input[third];
    };
    Solution.prototype.recursion = function (index) {
        if (this.returnValue === 0)
            return;
        var first = index.first, second = index.second, third = index.third;
        if (third > this.input.length - 1)
            return;
        if (first === second || second === third)
            return;
        // 상태 갱신
        var hap = this.input[first] + this.input[second] + this.input[third];
        if (hap === this.target) {
            this.renewal(index);
            this.returnValue = 0;
            return;
        }
        else if (this.closet === 0) {
            this.closet = Math.abs(hap);
            this.renewal(index);
            this.returnValue = Math.abs(hap);
            // 100 - 3 => 97
            // 100 - 2 => 98
        }
        else if (Math.abs(this.target - Math.abs(hap)) <
            Math.abs(this.target - this.closet)) {
            this.closet = Math.abs(hap);
            this.renewal(index);
            this.returnValue = Math.abs(hap);
        }
        // 재귀호출
        if (first === this.input.length - 3 &&
            second === this.input.length - 2 &&
            third === this.input.length - 1) {
            return;
        }
        index = __assign(__assign({}, index), { third: third + 1 });
        this.recursion(index);
        index = __assign(__assign({}, index), { second: second + 1 });
        this.recursion(index);
        index = __assign(__assign({}, index), { first: first + 1 });
        this.recursion(index);
    };
    Solution.prototype.run = function () {
        if (this.input.length < 3)
            return;
        this.recursion({
            first: 0,
            second: 1,
            third: 2
        });
        console.log(this.closetValue);
        return this.returnValue;
    };
    return Solution;
}());
function run() {
    var solution = new Solution([-3, -1, 1, 2], 1);
    console.log(solution.run());
}
exports["default"] = run;
