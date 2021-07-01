/*
    15:10 ~ 15:50
    Input string = "abaxyzzyxf"
    Ouput string = "xyzzyx"
    Constraint 
        - 0 <= n <= 10^5
    Edge Case
        - string.length none = ""
        - 중복된 output이 있을 경우 최초의 string을 반환
    Algorithm 
        - Two pointer
        - pointer1 front, back
        - pointer2 front, back
         abaxyzzyxf
pointer  ^^      ^^
pointer1, pointer2의 각각 pointer의 string.length / 2 ~ 사이 간격이 1
pointer1 => 문자열과
pointer2 => 문자열.revers가 같으면 Math.max(Output.lenght)
        ab xf
        .
        .
        zy xf
        ab yx
        .
        .
        ab ax

        aba yxf
    time = O(n)
*/
function thirdQuestion(str: string){
    let retVal = "";
    let pointer1 = {
        front: 0,
        back: 1
    }
    let pointer2 = {
        front: str.length - 2,
        back: str.length - 1
    }
    let len = 1;
    let switching = false;
    while(1){
        if(!switching){
            //pointer1의 위치를 오른쪽으로 옮기며 진행
            const first = [str].slice(pointer1.front, pointer1.back).join("");
            const back = [[str].slice(pointer2.front, pointer2.back)].reverse().join("");
            if(first === back){
                if((first + back).length > retVal.length){
                    retVal = first + back;
                }
            }
            pointer1.front++;
            pointer1.back++;
            if(pointer1.back >= pointer2.front){
                pointer1.front = 0;
                pointer1.back = pointer1.front + len
                switching = true;
                continue;
            }
        }else{
            //pointer2의 위치를 왼쪽으로 옮기며 진행
            const first = [str].slice(pointer1.front, pointer1.back).join("");
            const back = [[str].slice(pointer2.front, pointer2.back)].reverse().join("");
            if(first === back){
                if((first + back).length > retVal.length){
                    retVal = first + back;
                }
            }
            pointer2.front--;
            pointer2.back--;
            if(pointer2.front <= pointer1.back){
                len++;
                pointer1.front = 0;
                pointer1.back = pointer1.front + len

                pointer2.back = str.length - 1
                pointer2.front = pointer2.back - len
                switching = false;

                continue;
            }
        }
        console.log(len);
        if(len >= str.length / 2){
            break;
        }
    }
    return retVal;
}


export function run(){
    thirdQuestion("abaxyzzyxf");
}

// 면접관에 알고리즘 확인
// 짝수 홀수