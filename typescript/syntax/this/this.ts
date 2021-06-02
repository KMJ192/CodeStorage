const object = {
    name : "name",
    whoami : function () {
        console.log(this);
    }
}

export function thisRun(){
    //object의 this를 출력
    object.whoami();

    //현재 scope(thisRun 함수)의 this를 출력
    const who = object.whoami;
    who();
}

function onclickEvent(){
    const object = {
        name : "name",
        whoami : function () {
            console.log(this);
        }
    }
    object.whoami();
    
    const who = object.whoami;
    who();
}