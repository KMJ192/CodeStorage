const object = {
    name : "OBJ",
    whoami: function () {
        console.log(this);
        const thisTest = () =>{
            console.log(this);
        }
        thisTest();
    }
}

function thisTest(test: Function){
    test();
}
function bindTest(tmp : string){
    this.name = `bind${tmp}`;
    this.pw = "123";
}
function callTest(test: string){
    console.log(`call binding this.name : ${this.name}, this.pw : ${this.pw}`);
    console.log(test);
}

function applyTest(test1: string, test2: string){
    console.log(`${this.name}, ${this.pw}`);
    console.log(test1);
    console.log(test2);
}

class Temp{
    private str: string;
    constructor(){
        this.str = "";
    }
    setStr(data: string){
        this.str = data;
    }
    print(){
        console.log(`this ${this}`);
        console.log(`Temp's data: ${this.str}`);
    }
}

export function thisRun(){
    //암시적 바인딩 => this는 this가 속해있는 Object를 가리킨다.
    object.whoami();
    
    //암시적 소실 => this는 window를 가리킨다. (script mode => undefined)
    thisTest(object.whoami);

    // new => 함수를 객체로 만들어 준다. this는 해당 객체를 가리킨다.
    let newBinding = new bindTest();
    console.log(`${newBinding.name}, ${newBinding.pw}`);

    // call/apply binding => 첫번째 arg로 함수를 넣어주며 주번째 인자값은 해당 함수가 받을 parameter
    // this는 첫번째 arg로 넘겨준 함수를 가리킨다.
    callTest.call(bindTest, "test");
    applyTest.apply(bindTest, ["arg1", "arg2"]);

    let tmp = new Temp;
    tmp.setStr("123");
    tmp.print();
}

