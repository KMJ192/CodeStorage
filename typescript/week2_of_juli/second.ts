/*
//str1을 str2로 바꿀때 최소변화량 return
//조건1. 같은 문자 => 바꿀필요 없음
//조건2. 다른 문자 => {
                Math.min(replaction, deletion, substitution)

            }
    biting
    |
    mitten
*/
function run(str1: string, str2: string){
    if(!str1.length && str2.length) return str2.length;
    if(str1.length && !str2.length) return str1.length;

    const maxlen = str1.length > str2.length ? str1.length : str2.length;
    let comArr: number[] = Array.from({length: maxlen}, () => 0); 
    console.log(comArr);
    // for(let i = 0; i < maxlen; i++){
    //     if(!str1[i] && str2[i]) 
    // }
    // let max  = Array.from(Array(str1.length), () => Array(str2.length).fill(""));
    // console.log(max);
}

export function second() {
    let str1 = "biting";
    let str2 = "mitten";
    run(str1, str2);
}