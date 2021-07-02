"use strict";
exports.__esModule = true;
exports.selectionSort = void 0;
function selectionSort() {
    var array = [6, 5, 2, 4, 3, 1];
    for (var i = 0; i < array.length; i++) {
        var minIndex = i;
        for (var j = i + 1; j < array.length; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        var curr = array[minIndex];
        array[minIndex] = array[i];
        array[i] = curr;
    }
    console.log(array);
}
exports.selectionSort = selectionSort;
