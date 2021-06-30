//sliding window Algorithm
//two pointer(front, back)이용
//pointer의 이동시 counter의 증감
//back pointer가 이동할 때 마다 counter감소, counter가 대상의 길이보다 작을때 이동
//front pointer가 이동할 때 마다 counter증가

interface PointType{
    front: number;
    back: number;
}

function solution(tmp: string, goal: string){   
    let obj: any = {};
    let count = 0;
    let pointer: PointType = {
        front: 0,
        back: 0
    }

    for(let i = 0; i < goal.length; i++){
        if(obj[goal[i]]) { 
            obj[goal[i]] = ++obj[goal[i]];
        }else{
            obj[goal[i]] = 1;
        }
    }
    //{ s: 2, b: 1, d: 1 }
    let objArr = Object.keys(obj);

    let bPoint = true;
    while(bPoint){
        bPoint = false;
        console.log(obj);
        for(let i = 0; i < objArr.length; i++){
            if(obj[objArr[i]]) {
                bPoint = true;
                break;
            }
        }
        const b = obj[tmp[pointer.back]];
        if(b) {
            obj[tmp[pointer.back]]--;
            count++;
        }
        if(count < goal.length){
            pointer.back++;
            continue;
        }
        
        const f = obj[tmp[pointer.front]];
        if(f){
            obj
        }
        pointer.front++;
    }
}

export function runSlidingWindow(){
    //tmp내 goal의 문자열이 모두 포함되는 위치 구하기
    //원하는 결과값 sdbds
    const tmp = "asdbdssd";
    const goal = "sbds";

    solution(tmp, goal);
}