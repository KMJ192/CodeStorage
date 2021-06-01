struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut compare = 0;
        //왼쪽의 원소 i, 오른쪽의 원소 j
        for i in 0..prices.len(){
            for j in i..prices.len(){
                if prices[i] < prices[j] && compare < (prices[j] - prices[i]){
                    compare = prices[j] - prices[i];
                    println!("{} {} {}", i, j, compare);
                }
            }
        }
        compare
    }
}

pub fn run(){
    //왼쪽의 원소보다 오른쪽의 원소가 클 때 이익이 남
    let v = vec![7, 1, 5, 3, 6, 4];
    //let v = vec![7, 6, 4, 3, 1];
    let result = Solution::max_profit(v);
    println!("{}", result);
}