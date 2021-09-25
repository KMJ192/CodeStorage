/*
    11:48 ~ 12:18
    input: n, k
    output: char
*/

struct Solution;

impl Solution {
    pub fn find_kth_bit(n: i32, k: i32) -> char {
        if k == 0 { return '0';}
        let mut bit = String::from("0");

        Solution::recursion(&mut bit, 0, n);

        let mut answer: Vec<char> = bit.chars().collect();
        println!("{:?}", answer);
        answer[k as usize - 1]
    }

    fn recursion(prev: &mut String, idx: i32, n: i32) {
        if idx == n - 1 {
            return;
        }
        let mut bit = Solution::reverse(prev.clone());
        bit = Solution::invert(bit);

        prev.push_str("1");
        prev.push_str(&*bit);

        Solution::recursion(prev, idx + 1, n);
    }

    fn reverse(bit: String) -> String {
        bit.chars().rev().collect::<String>()
    }

    fn invert(bit: String) -> String {
        let mut value = String::from("");
        for c in bit.chars() {
            if c == '0' { value.push('1'); }
            else { value.push('0'); }
        }
        value
    }
}

pub fn run() {
    let tmp = Solution::find_kth_bit(4, 11);
    println!("{}", tmp);
}