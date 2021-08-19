"use strict";
// class Node<T> {
//   val: T;
//   next: Node;
//   constructor(val) {
exports.__esModule = true;
exports.dupZeros = void 0;
//   }
// }
// class Queue<T> {
//   private val: T[];
//   private length: number;
//   constructor() {
//     this.val = [];
//   }
//   public push(value: T) {
//   }
//   public pop(value: T) {
//   }
// }
function duplicateZeros(arr) {
    for (var i = 0; i < arr.length; i++) {
        var end = arr.length - 1;
        if (arr[i] === 0) {
            while (end > i + 1) {
                arr[end] = arr[end - 1];
                end--;
            }
            if (i + 1 < arr.length)
                arr[i + 1] = 0;
            i++;
        }
    }
    console.log(arr);
}
;
function dupZeros() {
    var arr = [1, 0, 2, 3, 0, 4, 5, 0];
    duplicateZeros(arr);
}
exports.dupZeros = dupZeros;
