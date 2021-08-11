"use strict";
exports.__esModule = true;
function main() {
    //AsteroidCollision();
    // const sampleArray = [1, 2, 3, 4, 5];
    // const hap = sampleArray.map(function (unit){
    //     return unit + unit
    // });
    // console.log(hap);
    //TSRun();
    var object = "메뉴1";
    var words = ["메뉴1", "메뉴2", "메뉴3", "메뉴4"];
    // let tmp = words.filter((word: string) =>{
    //     if(word !== '' && 
    //         object !== ''  && 
    //         word.includes(object) === true && 
    //         word[0] === object[0]) {
    //             console.log(word[0]);
    //             console.log(object[0]);
    //             return word;
    //     }
    // });
    //console.log(tmp);
    console.log(words.some(function (value) { return value === object; }));
}
main();
