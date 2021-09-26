/*
    < Feedback Template >
  0. Question/Solver : find kth bit in nth binary string / 김수환
  1. Problem Solving: 풀었다
  2. Coding : javascript 조건문 동치연산자 ==를 ===로 바꾸면 좋겟다.
  3. Communication : 의사 전달력 - 10점만점에 10점
  4. 잘한 것 : 코드가 작동하지 않을 때 침착하게 대응, 도전정신
  5. 좀 더 노력해야되는 부분 : 배열의 unshift 가 조금 아쉽다.

*/

struct Solution;

impl Solution {
    pub fn find_kth_bit(n: i32, k: i32) -> char {
        if k == 1 { return '0'; }
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