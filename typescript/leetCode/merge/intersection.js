"use strict";
exports.__esModule = true;
exports.intersection = void 0;
function intersection(nums1, nums2) {
    var answer;
    var tmp = {};
    nums1.forEach(function (val1) {
        nums2.forEach(function (val2) {
            if (val1 === val2) {
                tmp[val1] = val1;
            }
        });
    });
    console.log(tmp);
    return answer;
}
exports.intersection = intersection;
;
