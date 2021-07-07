"use strict";
exports.__esModule = true;
exports.third = void 0;
/*
    input = [75, 105, 120, 75, 90, 135]
    output = 330 // 75 + 120 + 135
    constraint = array is empty return 0
    Edge case
    Algorithm
        - recrucive
        - 첫번쨰 원소부터 시작하는 로직 -> 1칸 ~ array.length 각각 더하기
        - 두번째 원소부터 시작하는 로직 -> 1칸 ~ array.length 각각 더하기
    DS
    time O(n^2)
    space O(n^2)
*/
//배열, index, 인접길이, 이전값
function recrucive(array, i, adj, prev) {
    if (!array[i])
        return 0;
    console.log(array + ", " + i + ",  " + adj + ", " + prev);
    var max = 0;
    for (var n = i; n < array.length; n += adj) {
        // if(!(adj % n)){
        //     console.log(adj % n);
        // }
        console.log(n);
        max = Math.max(max, recrucive(array, n + adj, adj, prev + array[n]));
    }
    return max;
}
function maxSubsetSum(array) {
    //첫번째 원소부터 시작
    var max = 0;
    for (var i = 0; i < array.length; i++) {
        max = Math.max(max, recrucive(array, i, 1 + i, 0));
    }
    //두번째 원소부터 시작
    for (var i = 1; i < array.length; i++) {
        max = Math.max(max, recrucive(array, i, 1 + i, 0));
    }
    return max;
}
function third() {
    var array = [75, 105, 120, 75, 90, 135];
    console.log(maxSubsetSum(array));
}
exports.third = third;
