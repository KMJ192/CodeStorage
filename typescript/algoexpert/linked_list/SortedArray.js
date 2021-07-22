"use strict";
exports.__esModule = true;
exports.sortedArray = void 0;
function sa(array) {
    var left = 0;
    var right = array.length - 1;
    var tmp = [];
    while (left <= right) {
        var mid = Math.floor(left + ((right - left) / 2));
        if (array[mid] === mid && mid - 1 === array[mid - 1]) {
            right = mid - 1;
        }
        if (array[mid] === mid) {
            tmp.push(mid);
        }
        if (array[mid] < mid) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
        console.log("left : " + left + ", right : " + right + ", mid : " + mid);
    }
    console.log(tmp);
    return -1;
}
//[-5, -3, 2, 3, 4, 5, 9]
//  ^         ^        ^
function sortedArray() {
    var array = [-5, -3, 2, 3, 4, 5, 9];
    console.log(sa(array));
}
exports.sortedArray = sortedArray;
