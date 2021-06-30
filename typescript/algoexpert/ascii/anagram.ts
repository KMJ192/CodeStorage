//time complexity = O(n)
//space complexity = O(n)

function solution(words: string[]): string[][]{
    let cast : number[] = [];
    let retVal = [];

    for(let i = 0; i < words.length; i++){
        let tmp = 0;
        for(let j = 0; j < words[i].length; j++){
            tmp += words[i].charCodeAt(j);
        }
        cast.push(tmp);
    }

    for(let i = 0; i < cast.length; i++){
        let sort: string[] = []
        if(cast[i] === -1) continue;
        for(let j = i+1; j < cast.length; j++){
            if(cast[i] === cast[j]){
                if(sort.length) sort.push(words[j]);
                else {
                    sort.push(words[i]);
                    sort.push(words[j]); 
                }
                cast[j] = -1;
            }
        }
        if(sort.length) retVal.push(sort);
        else retVal.push([words[i]]);
    }
    return retVal;
}

export function runAnagram(){
    const words: string[] = ["yo", "act", "flop", "tac", "foo", "cat", "oy", "olfp", "tca", "a", "tmp", "mtp", "lopf"];
    let result: string[][] = solution(words);
    console.log(result);
}