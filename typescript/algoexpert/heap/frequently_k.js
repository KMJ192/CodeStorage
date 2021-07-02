"use strict";
exports.__esModule = true;
exports.fk = void 0;
function solution(arr, k) {
    if (!arr.length)
        return [];
    if (!k)
        return [];
    var ht = {};
    var retVal = [];
    var curr = [];
    //hash table
    for (var i = 0; i < arr.length; i++) {
        if (ht[arr[i]])
            ht[arr[i]]++;
        else
            ht[arr[i]] = 1;
    }
    console.log(ht);
    var key = Object.keys(ht);
    var value = Object.values(ht);
    //sort
    for (var i = 0; i < key.length; i++) {
        curr.push([value[i], key[i]]);
    }
    curr.sort();
    //convert
    for (var i = 0; i < k; i++) {
        retVal.push(Number(curr[curr.length - 1 - i][1]));
    }
    return retVal;
}
function fk() {
    //const arr = [1, 3, 5, 12, 11, 12];
    var arr = [5, 5, 5, 12, 5, 5, 5, 11, 3, 11, 12];
    console.log(solution(arr, 2));
}
exports.fk = fk;
//const arr = [1, 3, 5, 12, 11, 12, 11]; 2 => [12, 11]
//const arr = [5, 12, 11, 3, 11]; 2 => [11, 5] or [11, 12] or [11, 3]
