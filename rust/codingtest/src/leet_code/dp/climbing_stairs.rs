struct Solution;

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n == 0 { return 0;}
        else if n == 1 { return 1; }
        else if n == 2 { return 2; }

        let mut tmp1 = 1;
        let mut tmp2 = 2;
        let mut answer = 0;

        for i in 2..n{
            answer = tmp1 + tmp2;
            tmp1 = tmp2;
            tmp2 = answer;
        }
        answer
    }
}

pub fn run(){
    let n = Solution::climb_stairs(5);
    println!("{}", n);
}
// 0 => 0
// 1 => 1
// 2 => 2
// 3 => 3
// 4 => 5
// 5 => 8
// 6 => 13
// 7 => 21
// 8 => 34
// 9 => 55