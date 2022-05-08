"use strict";
// https://velog.io/@yh1120/JS-%ED%95%9C%EA%B8%80-%EC%9E%90%EC%9D%8C-%EB%B6%84%EB%A6%AC%ED%95%98%EA%B8%B0
exports.__esModule = true;
exports.hangulExtract = void 0;
var mockingData = [
    "한글",
    "한길",
    "한기러",
    "한기렇",
    "한기러하",
    "한기러하다",
];
function makeDictionary(s) {
    var sentence = s;
    var result = "";
    var korean = {
        chosung: [
            "ㄱ",
            "ㄲ",
            "ㄴ",
            "ㄷ",
            "ㄸ",
            "ㄹ",
            "ㅁ",
            "ㅂ",
            "ㅃ",
            "ㅅ",
            "ㅆ",
            "ㅇ",
            "ㅈ",
            "ㅉ",
            "ㅊ",
            "ㅋ",
            "ㅌ",
            "ㅍ",
            "ㅎ",
        ],
        jungsung: [
            "ㅏ",
            "ㅐ",
            "ㅑ",
            "ㅒ",
            "ㅓ",
            "ㅔ",
            "ㅕ",
            "ㅖ",
            "ㅗ",
            "ㅘ",
            "ㅙ",
            "ㅚ",
            "ㅛ",
            "ㅜ",
            "ㅝ",
            "ㅞ",
            "ㅟ",
            "ㅠ",
            "ㅡ",
            "ㅢ",
            "ㅣ",
        ],
        jongsung: [
            "",
            "ㄱ",
            "ㄲ",
            "ㄳ",
            "ㄴ",
            "ㄵ",
            "ㄶ",
            "ㄷ",
            "ㄹ",
            "ㄺ",
            "ㄻ",
            "ㄼ",
            "ㄽ",
            "ㄾ",
            "ㄿ",
            "ㅀ",
            "ㅁ",
            "ㅂ",
            "ㅄ",
            "ㅅ",
            "ㅆ",
            "ㅇ",
            "ㅈ",
            "ㅊ",
            "ㅋ",
            "ㅌ",
            "ㅍ",
            "ㅎ",
        ]
    };
    function isHangul(word) {
        if (word.length > 1)
            return false;
        var code = word.charCodeAt(0) - 0xac00;
        // 한글 범위 계산
        var start = "가".charCodeAt(0) - 0xac00;
        var end = "힣".charCodeAt(0) - 0xac00;
        return code >= start && code <= end;
    }
    function disassemble(c) {
        var r = [];
        var uniVal = c.charCodeAt(0) - 0xac00;
        var cho = Math.floor(uniVal / 28 / 21);
        var jung = Math.floor((uniVal / 28) % 21);
        var jong = Math.floor(uniVal % 28);
        if (korean.chosung[cho]) {
            r.push(korean.chosung[cho]);
        }
        if (korean.jungsung[jung]) {
            r.push(korean.jungsung[jung]);
        }
        if (korean.jongsung[jong]) {
            r.push(korean.jongsung[jong]);
        }
        return r;
    }
    function make() {
        for (var i = 0; i < sentence.length; i++) {
            var c = sentence[i];
            if (isHangul(c)) {
                var ext = disassemble(c);
                ext.forEach(function (d) {
                    // result.push(d);
                    result = "".concat(result).concat(d);
                });
            }
            else {
                // result.push(c);
                result = "".concat(result).concat(c);
            }
        }
    }
    var extractResult = function () {
        return result;
    };
    return {
        isHangul: isHangul,
        disassemble: disassemble,
        make: make,
        extractResult: extractResult
    };
}
function hangulExtract() {
    var han = makeDictionary("abcd한글 자동완성ㅇㅇㅇㅓㅓ 구현[][]");
    han.make();
    console.log(han.extractResult());
}
exports.hangulExtract = hangulExtract;
// 한글일 경우, 한글 + 영어일 경우, 영어일 경우
/**
  한글
    => 초성만 있을 경우, 중성만 있을 경우, 종성만 있을 경우 일단 고려하지 않음
    => 한글을 칠때 종성일수도 있고, 초성일 수도 있음
      -> 종성이 있을때, 다음 글자의 초성일 경우도 생각할것
 */
