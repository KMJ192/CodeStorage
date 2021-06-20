export function run(){
    let test: number = 0;
    const tmp: any = generatorFunc(test);
    tmp.next();
}

function* generatorFunc(input: number){
    console.log("시작");
    while(input < 10){
        console.log(input);
        yield input++;
    }
    return input;
}
