export function climbStairs(n: number): number {
    if(n === 0) return 0;
    if(n === 1) return 1;
    if(n === 2) return 2;
    let tmp1 : number = 1;
    let tmp2 : number = 2;
    let answer : number = 0;
    for(let i : number = 2; i < n; i++){
        answer = tmp1 + tmp2;
        tmp1 = tmp2;
        tmp2 = answer;
    }
    console.log(answer);
    return answer;
};