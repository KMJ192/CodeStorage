
function solution(arr: Array<number>, k: number): number[]{
    if(!arr.length) return [];
    if(!k) return [];

    let ht: any = {};
    let retVal: number[] = [];

    let curr = [];
    
    //hash table
    for(let i = 0; i < arr.length; i++){
        if(ht[arr[i]]) ht[arr[i]]++;
        else ht[arr[i]] = 1;
    }    

    //sort
    let key: string[] = Object.keys(ht);
    let value: number[] = Object.values(ht);
    for(let i = 0; i < key.length; i++){
        curr.push([value[i], key[i]]);
    }
    curr.sort();

    //making
    for(let i = 0; i < k; i++){
        retVal.push(Number(curr[curr.length - 1 - i][1]));
    }

    return retVal;
    
}

export function fk(){
    //const arr = [1, 3, 5, 12, 11, 12];
    const arr = [5, 5, 5, 12, 5, 5, 5, 11, 3, 11, 12];
    console.log(solution(arr, 2));
}