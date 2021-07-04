function solution(k, rates) {
    if(rates.length === 1) return k;
    let property = [k, 0]; //0 => 재산, 1 => 달러
    let start = 0;
    for(let i = start; i < rates.length; i++){
        if(k >= rates[i]){
            property[0] = k - rates[i];
            property[1] += 1;
            start = i;
            break;
        }
    }
    if(property[0] === k) return k;

    for(let i = start; i < rates.length; i++){
        if(i < rates.length - 2){
            if(property[1] > 0 && (rates[i]*property[1] > rates[i + 1]*property[1])){
                property[0] += rates[i];
                property[1]--;
                continue;
            }
            if(property[0] > rates[i] && rates[i] < rates[i + 1]){
                property[0] -= rates[i];
                property[1]++;
            }
        }else{
            if(property[0] > rates[i]){ 
                if(rates[i] < rates[i + 1]){ 
                    property[0] -= rates[i];
                    property[1]++;
                    property[0] += rates[i+1];
                    property[1]--;
                }
            }else{
                if(rates[i] > rates[i + 1]){ 
                    property[0] += rates[i];
                    property[1]--;
                }else{
                    property[0] += rates[i+1];
                    property[1]--;
                }
            }
        }
    }
    return property[0];
}

//가장 쌀때 사는것
//가장 비쌀때 파는것을 예상하기
//const rate = [1200, 1000, 1100, 1200, 900, 1000, 1500, 900, 750, 1100];
const rate = [1500, 1400, 1300, 1200];
console.log(solution(1500, rate));