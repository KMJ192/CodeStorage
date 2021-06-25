function solution(array){
    return dfs(array);
}
function dfs(array, deps = 1){
    let sum = 0;
    for(let i = 0; i < array.length; i++){
        const currentElement = array[i];
        //console.log(`현재 위치 : ${currentElement}`);
        if(Array.isArray(currentElement)){
            sum += dfs(currentElement, deps+1)
        }else{
            sum += currentElement;
        }
    }
    return deps * sum;
}

const array = [5, 2, [7, -1], 3, [6, [-13, 8], 4]];
console.log(solution(array));

// space O(d) => depth
// time O(n)
// function productSum(arr, multiplier = 1) {
//     let sum = 0;
//     for(let i = 0; i < arr.length; i++) {
//         const currentElement = arr[i];
//         // int or array
//         if(Array.isArray(currentElement)) {
//             sum += productSum(currentElement, multiplier + 1);
//         } else {
//             sum += currentElement;
//         }
//     }
//     return multiplier * sum;
// }

//const array = [5, 2, [7, -1], 3, [6, [-13, 8], 4]];
//console.log(productSum(array));