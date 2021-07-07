// You're given an array of arrays where each subarray holds two integer values and represents an item; the first integer is the item's  value, and the second integer is the item's weight. You're also given an integer representing the maximum capacity of a knapsack that you have.
// Your goal is to fit items in your knapsack without having the sum of their weights exceed the knapsack's capacity, all the while  maximizing their  combined value. Note that you only have one of each item at your disposal.
// Write a function that returns the maximized combined value of the items  you should pick as well as an array of the indices of each item picked
// If there are multiple combinations of items that maximize the total value in the knapsack, your function can return any of them.

function run(items: number[][], capacity: number){
    function recursion(items: number[][], capacity: number, index: number, max: number){
        
        for(let i = 0; i < items.length; i++){

        }
    }
    return recursion(items, capacity, 0, 0);
}

export function forthQuestion(){
    //가방의 무게, 가방의 가중치
    let items = [
        [1, 2],
        [4, 3],
        [5, 6],
        [6, 7]
    ];

    console.log(run(items, 10));
}
// 가방 무게 합계가 capacity를 초과하지 않으면서 가방의 결합 가치를 최대화 하는 것
// output => [10, [1, 3]] [결합한 가방의 무게, [n번째 가방, m번째 가방]]
// items[4, 3] and [6, 7]
// 나는 왜이렇게 개씨발 병신이지???