"use strict";
exports.__esModule = true;
exports.second = void 0;
//같은 패턴 찾기
function run(str1, str2) {
    if (!str1.length && str2.length)
        return str2.length;
    if (str1.length && !str2.length)
        return str1.length;
    var maxCount = str1.length > str2.length ? str1.length : str2.length;
    var pointer = {
        front: 0,
        back: 0
    };
    var cCount = 0;
    while (pointer.front < maxCount || pointer.back < maxCount) {
        if (str1[pointer.front] === str2[pointer.back]) {
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
function dp(str1, str2) {
    function recrusion(s1, s2, curIdxOne, curIdxTwo, opCount) { }
    //recrusion(str1, str2, 0, 0);
}
function second() {
    var str1 = "biting";
    var str2 = "mitten";
    console.log(run(str1, str2));
    console.log(dp(str1, str2));
}
exports.second = second;
