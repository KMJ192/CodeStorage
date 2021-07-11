function solution(items, capacity){
    if(!items.length || !capacity) return [];
    let dp = Array.from(Array(items.length), () => Array(capacity+1).fill(0));

    let index = [];

    //dp table
    for(let i = 0; i < items.length; i++){
        for(let j = 0; j < capacity+1; j++){
            if(i === 0){
                if(items[i][1] <= j) dp[i][j] = items[i][0];
            }else{
                if(j >= items[i][1]){
                    dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-items[i][1]] + items[i][0]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }

    //back traking
    let i = items.length;
    let j = capacity;
    while(0 < i){
        i--;
        if(i === 0) {
            if(dp[i][j] !== 0){
                index.push(i);
            }
            break;
        }
        if(dp[i][j] !== dp[i-1][j]){
            index.push(i);
            j = j - items[i][1];
        }
    }
    return [dp[items.length-1][capacity], index.reverse()];
}

const items = [
    [1, 2],
    [4, 3],
    [5, 6],
    [6, 7]
];

console.log(solution(items, 10));