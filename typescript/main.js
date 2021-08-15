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
    //thisRun();
}
var object = {
    name: 'Changmin'
};
function ChangMinHandler() {
    var name = this.name;
    return function todo() {
        console.log(name + " have to unlimit studing then die!!");
    };
}
var run = ChangMinHandler.bind(object);
var changmin = run();
//while(1) {
changmin();
//}
