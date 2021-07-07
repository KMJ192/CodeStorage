/*
    input = [75, 105, 120, 75, 90, 135]
    output = 330 // 75 + 120 + 135
    constraint = array is empty return 0
    Edge case
    Algorithm
        - recrucive
        - 첫번쨰 원소부터 시작하는 로직 -> 1칸 ~ array.length 각각 더하기
        - 두번째 원소부터 시작하는 로직 -> 1칸 ~ array.length 각각 더하기
    DS
    time O(n^2)
    space O(n)
*/
//배열, index, 인접길이, 이전값
// [75, 105, 120, 75, 90, 135] 
//  ^    ^
//  75  150

function recrucive(array: number[], i: number, adj: number, prev: number): number{
    if(!array[i]) return 0;
    console.log(`${array}, ${i}, ${adj}, ${prev}`)
    let max = 0;
    for(let n = i; n < array.length; n+=adj){
        max = Math.max(max, recrucive(array, n + adj, adj, prev + array[n]));
    }

    return max;
}

function maxSubsetSum(array: number[]){
    //첫번째 원소부터 시작
    let max = 0;
    for(let i = 0; i < array.length; i++){
        max = Math.max(max, recrucive(array, i, 1+i, 0));
    }

    //두번째 원소부터 시작
    for(let i = 1; i < array.length; i++){
        max = Math.max(max, recrucive(array, i, 1+i, 0));
    }
    return max;
}

export function third(){
    let array = [75, 105, 120, 75, 90, 135];
    console.log(maxSubsetSum(array));
}