function solution(money, cost) {
    let len = 0;
    let max = 0;
    if(money === 0){
        for(let i = 0; i < cost.length; i++){
            if(cost[i] !== 0){
                max = Math.max(len, max);
                len = 0;
                continue;
            }
            len++;
        }
        return max;
    }
    let bandwidth = [];
    for(let i = 0; i < cost.length; i++){
        if(cost[i] === 0){
            bandwidth.push(i);
        }
    }
    for(let i = 0; i < bandwidth.length-1; i++){
        let betweenPrice = 0;
        for(let j = bandwidth[i]; j < bandwidth[i+1]; j++){
            betweenPrice += cost[j];
        }
        if(betweenPrice < money){
            max = Math.max(max, bandwidth[i+1] - bandwidth[i]);
        }
    }

    return max ? max+2 : max;
}

const cost = [0, 900, 0, 200, 150, 30, 10, 0];
//const cost = [245, 317, 151, 192];
console.log(solution(420, cost));