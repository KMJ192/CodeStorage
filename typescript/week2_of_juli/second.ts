interface Pointer{
    front: number;
    back: number;
}

//같은 패턴 찾기
function run(str1: string, str2: string){
    if(!str1.length && str2.length) return str2.length;
    if(str1.length && !str2.length) return str1.length;

    const maxCount = str1.length > str2.length ? str1.length : str2.length;

    let pointer: Pointer = {
        front: 0,
        back: 0
    }
    let cCount = 0;

    while(pointer.front < maxCount || pointer.back < maxCount){
        if(str1[pointer.front] === str2[pointer.back]){
            pointer.front++;
            pointer.back++;
            continue;
        }

    }

    return cCount;
}

//조건1. 같은 문자 => 바꿀필요 없음
//조건2. str1의 다음 문자와 str2의 현재 문자가 같음 => str1을 가리키는 포인터 증가
//조건3. str1의 현재 문자와 str2의 다음 문자가 같음 => str2을 가리키는 포인터 증가
//조건4. str1의 다음 문자와 str2의 다음 문자가 같음 => str1, str2를 가리키는 포인터 증가

function dp(str1: string, str2: string){
    function recrusion(s1: string, s2: string, curIdxOne: number, curIdxTwo: number, opCount: number){}
    //recrusion(str1, str2, 0, 0);
}

export function second() {
    let str1 = "biting";
    let str2 = "mitten";
    console.log(run(str1, str2));
    console.log(dp(str1, str2));
}