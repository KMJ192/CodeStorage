"use strict";
//input : integer type array
//output : number(size)
//constraint 
// - n === height.length
// - 2 <= n <= 10^5
// - 0 <= height[i] <= 10^4
//Edge Case
//DS
exports.__esModule = true;
exports.run = void 0;
function maxArea(height) {
    var maxSize = 0;
    var pointer = {
        front: 0,
        back: 1
    };
    // let last = height.length - 1;
    // while(last){
    //     last--;
    //     let tmp = 0;
    //     if(height[pointer.front] > height[pointer.back]){
    //         tmp = height[pointer.back] * (pointer.back - pointer.front);
    //     }else{
    //         tmp = height[pointer.front] * (pointer.back - pointer.front);
    //     }
    //     if(maxSize < tmp){
    //         maxSize = tmp;
    //     }
    //     pointer.back++;
    // }
    //pointer.back 이동
    var tmp = 0;
    for (var i = 1; i < height.length; i++) {
        if (height[pointer.front] > height[pointer.back]) {
            tmp = height[pointer.back] * (pointer.back - pointer.front);
        }
        else {
            tmp = height[pointer.front] * (pointer.back - pointer.front);
        }
        if (maxSize < tmp) {
            maxSize = tmp;
        }
        if (height[pointer.front] < height[pointer.front + 1]) {
            pointer.front++;
        }
        console.log(pointer);
        pointer.back++;
    }
    pointer.back--;
    console.log(maxSize);
    for (var i = 0; i < height.length - 1; i++) {
        if (height[pointer.front] > height[pointer.back]) {
            tmp = height[pointer.back] * (pointer.back - pointer.front);
        }
        else {
            tmp = height[pointer.front] * (pointer.back - pointer.front);
        }
        if (maxSize < tmp) {
            maxSize = tmp;
        }
        console.log(pointer);
        pointer.front++;
    }
    console.log(maxSize);
    return maxSize;
}
// 시간 초과
// function maxArea_fail(height: number[]){
//     let maxSize = 0;
//     for(let i = 0; i < height.length; i++){
//         for(let j = i; j < height.length; j++){
//             const len = j - i;
//             if(height[i] > height[j]){
//                 if(maxSize < height[j] * len){
//                     maxSize = height[j] * len;
//                 }
//             }else{
//                 if(maxSize < height[i] * len){
//                     maxSize = height[i] * len;
//                 }
//             }
//         }
//     }
//     return maxSize;
// }
function run() {
    //let height: number[] = [1, 8, 6, 2, 5, 4, 8, 3, 7];
    //let height: number[] = [1, 2, 6, 2, 5, 4, 1, 3, 1];
    //let height: number[] = [1, 2]; // => 1
    //let height: number[] = [2, 1]; // => 1
    //let height: number[] = [0, 2]; // => 0
    var height = [1, 2, 4, 3]; // => 4
    console.log(maxArea(height));
}
exports.run = run;
//    f                    b
//[1, 8, 6, 2, 5, 4, 8, 3, 7]
// 0  8  0  2  15 16 40 18 49
// f  b
//[1, 8, 6, 2, 5, 4, 8, 3, 7]
//if(front < back) 둘다이동?
//     |
//     | |
//   | | |
// | | | | => 4
//   |
// | | |   => 2
//   |
// | |     => 1
// |  
// | |     => 1
//   |
//   |     => 0
