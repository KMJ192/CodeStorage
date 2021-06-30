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
    //{ s: 2, b: 1, d: 1 }
    var objArr = Object.keys(obj);
    var bPoint = true;
    while (bPoint) {
        bPoint = false;
        for (var i = 0; i < objArr.length; i++) {
            if (obj[objArr[i]] !== 0) {
                bPoint = true;
                break;
            }
        }
        console.log(obj);
        console.log(count);
        if (count < goal.length) {
            if (obj[tmp[pointer.back]]) {
                obj[tmp[pointer.back]]--;
                count++;
            }
            pointer.back++;
            continue;
        }
        if (obj[tmp[pointer.front]]) {
            obj[tmp[pointer.front]]++;
            count--;
        }
    }
    pointer.back--;
    console.log(pointer);
}
function runSlidingWindow() {
    //tmp내 goal의 문자열이 모두 포함되는 위치 구하기
    //원하는 결과값 sdbds
    var tmp = "sdbdsasd";
    var goal = "bdssa";
    solution(tmp, goal);
}
exports.runSlidingWindow = runSlidingWindow;
