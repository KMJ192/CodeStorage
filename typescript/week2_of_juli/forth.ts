// You're given an array of arrays where each subarray holds two integer values and represents an item; the first integer is the item's  value, and the second integer is the item's weight. You're also given an integer representing the maximum capacity of a knapsack that you have.
// Your goal is to fit items in your knapsack without having the sum of their weights exceed the knapsack's capacity, all the while  maximizing their  combined value. Note that you only have one of each item at your disposal.
// Write a function that returns the maximized combined value of the items  you should pick as well as an array of the indices of each item picked
// If there are multiple combinations of items that maximize the total value in the knapsack, your function can return any of them.

/*
    가방 무게 합계가 capacity를 초과하지 않으면서 가방의 결합 가치를 최대화 하는 것
    output => [10, [1, 3]] [결합한 가방의 무게, [n번째 가방, m번째 가방]]
    items[4, 3] and [6, 7]

    time complexity: O(n)
    space complexity: O(1)
*/

function run(items: number[][], capacity: number){
    if(!items.length) return [0];
    if(!capacity) return [0];

    // 원소의 가중치가 가장 높으면서도 무게가 capacity보다 작은 원소를 저장할 길이가 2인 배열
    let topTwo: number[][] = []; 
    // topTwo배열에 입력되어 있는 원소의 index값 저장
    let index: number[] = []; 
    //topTwo 배열의 변화를 감지
    let pFlag = false; 

    for(let i = 0; i < items.length; i++){
        if(pFlag){
            pFlag = false;
            if(topTwo[0][1] > topTwo[1][1]){
                topTwo = [topTwo[1], topTwo[0]];
                index = [index[1], index[0]];
            }
        }
        if(!topTwo.length){
            if(items[i][1] < capacity) {
                topTwo.push(items[i]);
                index.push(i);
            }
            continue;
        }
        //가중치가 작은것이 0번째 원소
        if(topTwo.length === 1){
            if(items[i][0] + topTwo[0][0] <= capacity) {
                topTwo.push(items[i]);
                index.push(i);
                pFlag = true;
                continue;
            }
        }
        //items의 현재 원소의 가중치가 topTwo 원소의 가중치보다 큰것이 있을 경우
        if(topTwo[0][1] < items[i][1] || topTwo[1][1] < items[i][1]){
            if(topTwo[1][0] + items[i][0] <= capacity){
                topTwo[0] = items[i];
                index[0] = i;
                pFlag = true;
            }else if(topTwo[0][0] + items[i][0] <= capacity){
                topTwo[1] = items[i];
                index[1] = i;
                pFlag = true;
            }
        }
    }
    return [topTwo[0][0] + topTwo[1][0], [index[0], index[1]]];
    
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
