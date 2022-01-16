"use strict";
exports.__esModule = true;
/*
  16: 37 ~ 17:07
  Given an array of intervals representing ‘N’ appointments,
  find out if a person can attend all the appointments.
  N개 appointments
  3개 appointments
 
  [[1,4], [2,5], [7,9]] -> false
  i: int 2d-array
  o: boolean
  e: 0 -> appointments true
  c: 0 <= array.length <= 1000

  [[6,7], [2,4], [8,12]]

  p
  brute force
  for(let i = 0; i < arr.len - 1; i++) {
    현재 arr[i][1]
    다음 arr[i+1][0]
    현재 > 다음 return false;
  }

  time : O(nlogn + n)
  space: O(1)
*/
function appo(array) {
    array.sort(function (a, b) { return a[0] - b[0]; });
    for (var i = 0; i < array.length - 1; i++) {
        var now = array[i][1];
        var next = array[i + 1][0];
        if (now > next)
            return false;
    }
    return true;
}
function run() {
    console.log(appo([
        [1, 1],
        [2, 2],
        [3, 3],
    ]));
}
exports["default"] = run;
