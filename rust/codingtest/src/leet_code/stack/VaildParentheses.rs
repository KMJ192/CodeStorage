struct Solution;

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut st : Vec<char> = Vec::new();
        for c in s.chars(){
            if c == '(' || c == '[' || c == '{' {
                st.push(c);
                continue;
            }
            if st.is_empty(){
                if c == ')' || c == '}' || c == ']' { return false; }
            }
            if c == ')' && !st.is_empty() && st[st.len() - 1] != '(' { return false; }
            if c == '}' && !st.is_empty() && st[st.len() - 1] != '{' { return false; }
            if c == ']' && !st.is_empty() && st[st.len() - 1] != '[' { return false; }
            if !st.is_empty(){
                st.pop();
            }
        }
        if !st.is_empty() { return false; }
        true
    }
}

pub fn run(){
    println!("{}" ,Solution::is_valid("(){()}".parse().unwrap()));
}