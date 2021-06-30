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
// ===========================================================
/*
  15:10 ~ 15:50
  
  Input:
    An array of strings
  Output:
    An 2d-array of anagram-groups
  Constraints:
    1 <= input.length <= 100
    1 <= word.length <= 100 = k
  Edge Case:
    If input.length === 1, [input];
  Solution:
    ["yo", "act", "flop", "tac", "foo", "cat", "oy", "olfp"]
    
    const ht = {
      "oy": ["yo", "oy"],
      "act": ["act", "tac", "cat"],
      "flop": ["flop", "olfp"],
      "foo": ["foo"],
    }

    return Object.values(ht);

    1. 배열의 각 단어들을 스캔 해 나간다.
      - 각 단어를 스캔할때, 단어를 오름차순으로 정렬하여 그 정렬된 단어가 ht 안에 key로서
      존재하고 있는지를 확인.
        - 만약 존재하고 있다면, 그 key의 value array로 그냥 push 해준다.
        - 만약 존재하고 있지 않다면, 정렬된 현 단어로 새로운 key를 만들어주고 value = [정렬된 단어]

    2. 배열의 각 단어들의 스캔이 끝난 후, ht 오브젝트의 밸류들을 묶은 배열을 리턴 해 준다.
  Time Complexity:
    O(N * klogk) when N = words.length, k = max(word.length)
  Space Complexity::
    O(N)
*/
// function Solution(words) {
//   const ht = {};
//   for (let i = 0; i < words.length; i++) {
//     const sorted = [...words[i]].sort().join("");
//     if (!ht[sorted]) ht[sorted] = [];
//     ht[sorted].push(words[i]);
//   }
//   return Object.values(ht);
// }
// const input = ["yo", "act", "flop", "tac", "foo", "cat", "oy", "olfp"];
// console.log(Solution(input));
