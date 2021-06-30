"use strict";
//sliding window Algorithm
//two pointer(front, back)이용
//pointer의 이동시 counter의 증감
//back pointer가 이동할 때 마다 counter감소, counter가 대상의 길이보다 작을때 이동
//front pointer가 이동할 때 마다 counter증가
exports.__esModule = true;
exports.runSlidingWindow = void 0;
function solution(tmp, goal) {
    var obj = {};
    var count = 0;
    var pointer = {
        front: 0,
        back: 0
    };
    for (var i = 0; i < goal.length; i++) {
        if (obj[goal[i]]) {
            obj[goal[i]] = ++obj[goal[i]];
        }
        else {
            obj[goal[i]] = 1;
        }
    }
    console.log(obj);
    var objLength = Object.keys(obj).length;
    // let sb = 100;
    // while(1){
    //     const c = obj[tmp[pointer.back]];
    //     if(c){
    //         obj[tmp[pointer.back]]--;
    //     }
    //     if(count < goal.length){
    //         pointer.back++;
    //         continue;
    //     }
    //     for(let i = 0; i < objLength; i++){
    //     }
    // }
}
function runSlidingWindow() {
    //tmp내 goal의 문자열이 모두 포함되는 위치 구하기
    //원하는 결과값 sdbds
    var tmp = "asdbdssd";
    var goal = "sbds";
    solution(tmp, goal);
}
exports.runSlidingWindow = runSlidingWindow;
