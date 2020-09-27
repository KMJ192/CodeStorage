fn solution(prices : Vec<i32>) -> Vec<i32>{

    let mut answer :Vec<i32> = Vec::new();
    
    for i in 0 .. prices.len(){
        let mut count : i32= 0;
        let com  = i + 1;
        for j in com .. prices.len(){
            //현재의 가격(prices[i])와 이후의 가격(prices[j]) 비교
            if prices[j] < prices[i]{
                count += 1;
                break;
            }else{
                count += 1;
            }
        }
        answer.push(count);
    }
    answer
}

fn main() {
    let mut prices : Vec<i32> = Vec::new();

    prices = [1, 2, 3, 2, 3].to_vec();

    for i in solution(prices){
        print!("{}", i);
    }
}