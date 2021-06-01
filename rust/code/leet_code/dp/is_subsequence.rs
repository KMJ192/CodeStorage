struct Solution;
impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        if s.len() == t.len() && s != t { return false; }
        let text : Vec<char> = t.chars().collect();
        let mut next: usize = 0;
        for c in s.chars(){
            let mut next_step : bool = false;
            for i in next..text.len(){
                if text[i] == c{
                    next = i + 1;
                    next_step = true;
                    break;
                }
            }
            if next_step == false {
                return false;
            }
        }
        true
    }
}

pub fn run(){
    let s = "bb";
    let t = "ahbgdc";
    let result = Solution::is_subsequence(s.parse().unwrap(), t.parse().unwrap());
    println!("{}", result);
}