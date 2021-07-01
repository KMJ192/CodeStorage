"use strict";
/*
    //input배열이 주어질 때 3개의 원소의 합이 0인 집합을 return
    //각 원소의 index는 모두 달라야 한다.

    input: number array = [-1,0,1,2,-1,-4];
    output: 2d-number array = [[-1,-1,2],[-1,0,1]];
    Constraint
        - 0 <= nums.length <= 3000
        - -10^5 <= nums[i] <= 10^5
    Edge Case
        - Inputed Empty array
        - Inputed array value 0
    Brute force
        - recursive
    Sudo Code
        
    
    time : O(n^2);
    space: O(n);

    nums[i] = -(nums[n] + nums[m])
    
    */
// [-1,0,1,2,-1,-4]
//  ^  ^ ^ 
// [-1,0,1,2,-1,-4]
//  ^  ^   ^ 
// [-1,0,1,2,-1,-4]
//  ^  ^      ^ 
// [-1,0,1,2,-1,-4]
//  ^  ^         ^ 
exports.__esModule = true;
exports.run = void 0;
// [-1,0,1,2,-1,-4]
//  ^    ^ ^
// [-1,0,1,2,-1,-4]
//  ^    ^    ^
// [-1,0,1,2,-1,-4]
//  ^    ^       ^
// [-1,0,1,2,-1,-4]
//  ^      ^     ^
// [-1,0,1,2,-1,-4]
//  ^         ^  ^
// [-1,0,1,2,-1,-4]
//  ^      ^  ^
// [-1,0,1,2,-1,-4]
//  ^      ^     ^
// [-1,0,1,2,-1,-4]
//  ^         ^  ^
// [-1,0,1,2,-1,-4]
//     ^ ^ ^
// [-1,0,1,2,-1,-4]
//     ^ ^    ^
// [-1,0,1,2,-1,-4]
//     ^ ^       ^
// [-1,0,1,2,-1,-4]
//     ^   ^  ^
// [-1,0,1,2,-1,-4]
//     ^   ^     ^
// [-1,0,1,2,-1,-4]
//     ^      ^  ^
// interface Pointer{
//     front:number;
//     middle:number;
//     back:number;
// }
//원본배열, 현재index, 합, 진행상태(array)
// function threeSum(nums: number[]): number[][] {
//     if(nums.length < 3) return [];
//     let retVal: number[][] = [];
//     let pointer: Pointer = {
//         front: 0,
//         middle: 1,
//         back: 2
//     }
//     let init: Pointer = pointer;
//     while(1){
//         if(nums.length - 3 <= pointer.front) break;
//         if(nums[pointer.front] + nums[pointer.middle] + nums[pointer.back] === 0){
//             retVal.push(
//                 [nums[pointer.front], nums[pointer.middle], nums[pointer.back]]
//             );
//         }
//         console.log(pointer);
//         //console.log(`${nums[pointer.front]}, ${nums[pointer.middle]}, ${nums[pointer.back]}`);
//         if(pointer.back > nums.length - 1){
//             //back이 배열의 끝보다 커졌다.
//             //이전 최초 위치의 한칸 증가한곳에 위치시킨다.
//             init.back++;
//             pointer.back = init.back;
//         }else{
//             //back을 1칸 옮긴다.
//             pointer.back++;
//         }
//         if(pointer.middle >= pointer.back){
//             //middle의 위치가 back의 위치보다 클경우
//             //이전 최초 위치의 한칸 증가한 곳에 위치시킨다.
//             init.middle++;
//             pointer.middle = init.middle;
//         }else{
//             pointer.middle++;
//         }
//         if(pointer.front >= pointer.middle){
//             //front의 위치가 middle의 위치보다 클 경우
//             //이전 최초 위치의 한칸 증가한 곳에 위치시킨다.
//             init.front++;
//             pointer.front = init.front;
//         }else{
//             pointer.front++;
//         }
//     }
//     return retVal;
// };
//0 1 2 <
//0 1 3
//0 1 4
//0 1 5
//0 2 3
//0 2 4
//0 2 5
//0 3 4
//0 3 5
//0 4 5
//1 2 3 <
//1 2 4
//1 2 5
//1 3 4
//1 3 5
//1 4 5
//2 3 4 <
//2 3 5
//2 4 5
//3 4 5
function threeSum(nums) {
    var triplets = [];
    if (nums.length < 3)
        return [];
    nums.sort();
    console.log(nums);
    for (var i = 0; i < nums.length; i++) {
        if (i > 0 && nums[i] === nums[i - 1])
            continue;
        var j = i + 1;
        var k = nums.length - 1;
        while (j < k) {
            if (nums[i] + nums[j] + nums[k] > 0) {
                k--;
            }
            else if (nums[i] + nums[j] + nums[k] < 0) {
                j++;
            }
            else {
                triplets.push([nums[i], nums[j], nums[k]]);
                while (j < k && nums[j] === nums[j + 1])
                    j++;
                while (j < k && nums[k] == nums[k - 1])
                    k--;
                j++;
                k--;
            }
        }
    }
    return triplets;
}
function run() {
    var nums = [-1, 0, 1, 2, -1, -4];
    console.log(threeSum(nums));
}
exports.run = run;
