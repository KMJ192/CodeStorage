struct Solution;

impl Solution {
    pub fn number_of_matches(mut n: i32) -> i32 {
        if n == 1 { return 0; }
        let mut result = 0;
        let mut matches = 0;
        while n != 1 {
            if n % 2 == 0 {
                n = n / 2;
                matches = n;
            }else{
                n -= 1;
                n = n / 2;
                matches = n;
                n += 1;
            }
            result += matches;
        }
        result
    }
}

pub fn run(){
    println!("{}", Solution::number_of_matches(14));
}