//분
function minuteCal() {
    let date = new Date();
    console.log(date);
    console.log("분");
    date.setMinutes(date.getMinutes() - 200);
    console.log(date);
}

//일
function dayCal(){
    console.log("일");
    let date = new Date();
    date.setDate(date.getDate() - 200);
    console.log(date);
}

//주
function weekCal(){
    console.log("주");
    let date = new Date();
    date.setDate(date.getDate() - (200*7));
    console.log(date);
}

//월
function monthCal(){
    console.log("월");
    let date = new Date();
    date.setMonth(date.getMonth() - 200);
    console.log(date);
}

export function dateCalculation(){
    // minuteCal();
    // dayCal();
    // weekCal();
    // monthCal();
    let date = new Date();
    console.log(date);
    date.setMonth(date.getMonth() - 2);
    console.log(date);
}