function classClosure(){
    let fn: string = "classClosure";
    return class Closure{
        name: string = "some";
        pw: string = "1234";
        constructor(name: string, pw: string){
            this.name = name;
            this.pw = pw;
        }

        display(){
            console.log(`user : ${this.name}, pw : ${this.pw}, fn : ${fn}`);
        }
        rtThis(){
            return {
                name: this.name,
                pw: this.pw,
                fn: fn
            }
        }
    }
}

const global = (function() {
    let innerText : string = "innerText";
    function examOne(): [string, (cText: string) => void]{
        const setText = (cText: string) => {
            innerText = cText;
        }
        return [innerText, setText];
    }
    return {
        examOne
    }
})();


class Test{
    test: string = "";
    constructor(tmp: string){
        this.test = tmp;
    }
    display(){
        console.log(this.test);
    }
}
export function closureFunc(){
    
    let test = new Test("123");
    test.display();
}