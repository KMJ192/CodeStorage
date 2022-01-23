"use strict";
// declare global {
//   interface machine {
//     // q: string;
//     // w: string;
//   }
// }
exports.__esModule = true;
function machine() {
    this.q = "strike";
    this.w = "snowball";
}
function pt() {
    machine.prototype.name = "kim";
    var nunu = new machine();
    console.log(nunu.name);
}
exports["default"] = pt;
