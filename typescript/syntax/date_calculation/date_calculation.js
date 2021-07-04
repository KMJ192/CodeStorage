"use strict";
exports.__esModule = true;
exports.dateCalculation = void 0;
//분
function minuteCal() {
    var date = new Date();
    console.log(date);
    console.log("분");
    date.setMinutes(date.getMinutes() - 200);
    console.log(date);
}
//일
function dayCal() {
    console.log("일");
    var date = new Date();
    date.setDate(date.getDate() - 200);
    console.log(date);
}
//주
function weekCal() {
    console.log("주");
    var date = new Date();
    date.setDate(date.getDate() - (200 * 7));
    console.log(date);
}
//월
function monthCal() {
    console.log("월");
    var date = new Date();
    date.setMonth(date.getMonth() - 200);
    console.log(date);
}
function dateCalculation() {
    // minuteCal();
    // dayCal();
    // weekCal();
    // monthCal();
    var date = new Date();
    console.log(date);
    date.setMonth(date.getMonth() - 2);
    console.log(date);
}
exports.dateCalculation = dateCalculation;
