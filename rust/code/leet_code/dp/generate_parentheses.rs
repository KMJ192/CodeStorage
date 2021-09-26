/*
    input : integer type n
    output : n개로 만들 수 있는 parentheses 를 모두 return
    constraint : 1 <= n <= 8
    ex)
     - n = 3
     - "((()))", "(()())", "(())()", "()()()"
     - n = 4
     - "(((())))", "(()()())", "((()))()", ... "()()()()"

     pattern
      - 하나의 String 에 n개의 parenthesis 들어옴
      - 여는 parenthesis 가 있어야 닫는 parenthesis 가 올 수 있다.

     solution
      - recursion
      - arg => input n, opened parenthesis count, progress string
      - return => Vec<String>

 //풀이
 //1. n이 1이면 걍 return
 //2. recursion 함수에 재귀호출
 //3. 여는 괄호 갯수와 닫는 괄호 갯수가 일치하면 문자열을 return
*/
/*
             (
        /    |    \
      (      (     )
     / \     / \
    (   )
   /   / \
  )   (   )
  |
  )
  |
  )
*/
struct Solution;
impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        if n == 1 { return vec![String::from("()")]; }

        let mut ret_val: Vec<String> = vec![];
        let mut recursion = |n: i32, open: i32, close: i32, mut prev: &str, option: String|{
            if open == close {
                ret_val.push(prev);
                return;
            }
            prev.push_str(&option);
            recursion(n, open+1, close, &prev, String::from("("));
            recursion(n, open, close+1, &prev, String::from(")"));
        }

        recursion(n, 1, 0, "", String::from("("));

        ret_val
    }


}

pub fn run(){
    let n = 3;
    println!("{:?}", Solution::generate_parenthesis(n));
}