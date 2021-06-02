"use strict";
exports.__esModule = true;
var this_1 = require("./syntax/this/this");
function main() {
    //asyncProcess();
    //closureFunc();
    this_1.thisRun();
}
//main();
var obj = {
    a: "a",
    b : function (){
        setTimeout(() => {
            console.log(this);
        }, 1000);
    }
};
obj.b();