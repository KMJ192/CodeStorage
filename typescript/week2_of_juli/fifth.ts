/*
    11:03 ~ 11: 43
    5번
    input: number array [1, 2, 3]
    output: number array [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
    constraint
        - 배열내 원소는 unique값
        - 0 <= 배열의 길이 <= 100
    edge case
    algorithm/ds
        - recursion
    time - O(n^2)
    space - O(n)
    sudo code 
    recursion(array, index){
        outputArr = recursion(array)
        return outputArr
    }
    for(array.length){
        recursion(array, i);
    }
*/
//[1, 2, 3]
// ^

function recursion(array: number[], obj: any, curArr: number[], retVal: number[][]){
    if(!obj) return [];
    
    for(let i = 0; i < array.length; i++){
        if(obj[array[i]]) {
            curArr.push(obj[array[i]])
            delete obj[array[i]];
            recursion(array, obj, curArr, retVal);
            retVal.push(curArr);
        }
    }
    console.log(retVal);
    return retVal;
}

function run(array: number[]){
    if(!array.length) return [];
    let obj: any = {}; 
    for(let i = 0; i < array.length; i++){
        obj[array[i]] = 0;
    }
    let curArr: number[] = [];
    let retVal: number[][] = [];
    recursion(array, obj, curArr, retVal);
}

export function w2Fifth(){
    const arr = [1, 2, 3]
    run(arr);
}

// function Solution(arr) {
//     // Edge Case:
//     if (arr.length === 0) return [];
  
//     // Construct ht out of arr
//     const arrHT = {};
//     for (let i = 0; i < arr.length; i++) {
//       arrHT[arr[i]] = true;
//     }
  
//     const retArr = [];
//     getPermutation(arrHT, [], retArr);
  
//     return retArr;
//   }
  
//   function getPermutation(numHT, permutation, retArr) {
//     const nums = Object.keys(numHT);
  
//     // Base Case
//     if (nums.length === 0) return retArr.push(permutation);
  
//     // General Case
//     for (let i = 0; i < nums.length; i++) {
//       permutation.push(Number(nums[i]));
//       delete numHT[nums[i]];
//       getPermutation(numHT, [...permutation], retArr);
//       numHT[nums[i]] = true;
//       permutation.pop();
//     }
//   }