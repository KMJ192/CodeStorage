struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut answer = 0;
        let mut compare = prices[0];
        for i in prices.iter(){
            //왼쪽 원소보다 오른쪽 원소가 클때
            if i > &compare {

            }
        }

        answer
    }
}

pub fn run(){
    //왼쪽의 원소보다 오른쪽의 원소가 클 때 이익이 남
    let v = vec![7, 1, 5, 3, 6, 4];
    let result = Solution::max_profit(v);
    println!("{}", result);
}