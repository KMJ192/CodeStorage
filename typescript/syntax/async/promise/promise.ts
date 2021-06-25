function example(): Promise<any>{
    return new Promise((resolve: any, reject: any) => {
        try{
            setTimeout(() => {
                resolve(1);
            }, 1000);
        }catch(e: any){
            reject(e);
        }
    })
}

export function promiseRun(){
    example()
        .then((value: any) => value + value) // promise의 실행 결과를 가져온다 => value = 1이며, 1+1 연산을 수행한다.
        .then((value: any) => value + value) // 그 다음 promise가 실행되며 이전 결과값의 2에서 2+2를 수행한다.
        .then((value: any) => console.log(value)) // 최종 결과는 4
        .catch((error: any) => console.log(error)); //바로 위의 then에서 오류가 발생할 경우 error를 표시한다.
}