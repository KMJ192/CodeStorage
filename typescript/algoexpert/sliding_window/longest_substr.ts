/*
10:05 ~ 10:40
    input
        - string, number
        - araaci, 2 => 4 
    Output
        - k이하의 갯수의 문자를 담는 문자열의 길이를 반환
    Constraint
        - 1 <= string
        - 모든문자
        - 1 <= k
    Edge Case
    DS 
        - hash map
    Algorithm 
        - two pointer
    
*/

//right가 이동하며 조건에 만족하지 않는 경우 left를 이동시키기.
//pointer이동 조건에 대한 문제 의도 파악 미흡.

//"araaci"
// ^ ^
// curr [["ara"]["araa"][]]
function run(str: string, k: number){
    let pointer = {
        front: 0,
        back: k - 1
    }
    let max = 0;

    while(pointer.back <= str.length){
        let hm: any = {};
        for(let i = pointer.front; i < pointer.back; i++){
            if(hm[str[i]]) hm[str[i]]++;
            else hm[str[i]] = 1;
        }

        let com: number[] = Object.values(hm);
        if(k < com.length){
            pointer.front++;
        }else{
            max = Math.max(max, com.reduce(function add(sum: number, currValue: number){
                return sum + currValue;
            }, 0));
            pointer.back++;
        }
    }

    return max;
}

export function longSubstring(){
    console.log(run("araaaaci", 2));
}