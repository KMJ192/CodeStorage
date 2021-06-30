"use strict";
//time complexity = O(n)
//space complexity = O(n)
exports.__esModule = true;
exports.runAnagram = void 0;
function solution(words) {
    var cast = [];
    var retVal = [];
    for (var i = 0; i < words.length; i++) {
        var tmp = 0;
        for (var j = 0; j < words[i].length; j++) {
            tmp += words[i].charCodeAt(j);
        }
        cast.push(tmp);
    }
    for (var i = 0; i < cast.length; i++) {
        var sort = [];
        if (cast[i] === -1)
            continue;
        for (var j = i + 1; j < cast.length; j++) {
            if (cast[i] === cast[j]) {
                if (sort.length)
                    sort.push(words[j]);
                else {
                    sort.push(words[i]);
                    sort.push(words[j]);
                }
                cast[j] = -1;
            }
        }
        if (sort.length)
            retVal.push(sort);
        else
            retVal.push([words[i]]);
    }
    return retVal;
}
function runAnagram() {
    var words = ["yo", "act", "flop", "tac", "foo", "cat", "oy", "olfp", "tca", "a", "tmp", "mtp", "lopf"];
    var result = solution(words);
    console.log(result);
}
exports.runAnagram = runAnagram;
