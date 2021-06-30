//======================================
/* 
    3:50 ~ 4:30
    input: string = "AlgoExpert is the best!"
    output: string = "best! the is AlgoExpert"
    constraint
        - 0 <= input.length <= 10^4
    Edge case
        - input.length === 0 => output ""
        - "asdasd   qsad" => "qsad   asdasd" 바뀌어진 문자열 사이의 space의 길이는 일정해야된다.
        - split, reverse method사용 금지
    Solution
        int front = 0, back = 0
        array return = []
        array tmp = []
        for(let i = 0; i < string.length; i++)
            back++;
            tmp.push(string[i])
            if(string[i] === " ")
                return.push(tmp.join(""))
                tmp.clear()
                for(let j = i; string.length; j++){
                    if(string[j] !== " "){
                        for(let n = 0; n < j-i; n++){
                            tmp.push(" ");
                        }
                        i = j;
                        return.push(tmp.join(""));
                        front = j
                        break;
                    }
                }
        
        return = ["AlgoExpert", " ", "is", " ", "the", " ",  "best!"]
        for(return 길이 / 2)
                자리 바꿔주기

    time: O(n)
    space: O(n)

    //1. sudo코드 작성 전 example 확인
    //2. solution코드 작성 전 time, splace complex 작성
    //3. Edge Case 코드에 반영
*/

function solution(str: string) {
    if(!str.length){ return ""; }
    
    let tmp = [];
    let retArr = [];
  
    for (let i = 0; i < str.length; i++) {
      if (str[i] === " ") {
        retArr.push(tmp.join(""));
        tmp = [];
        for (let j = i; j < str.length; j++) {
          if (str[j] !== " ") {
            i = j - 1;
            break;
          } else {
            tmp.push(" ");
          }
        }
        retArr.push(tmp.join(""));
        tmp = [];
      } else if (i === str.length - 1) {
        tmp.push(str[i]);
        retArr.push(tmp.join(""));
      } else {
        tmp.push(str[i]);
      }
    }
  
    for (let i = 0; i < retArr.length / 2; i++) {
      const front: string = retArr[i];
      const back: string = retArr[retArr.length - 1 - i];
      retArr[i] = back;
      retArr[retArr.length - 1 - i] = front;
    }
  
    return retArr.join("");
  }
export function runReversString(){
    let str: string = "AlgoExpert is the best!";
    console.log(solution(str));
}
  

