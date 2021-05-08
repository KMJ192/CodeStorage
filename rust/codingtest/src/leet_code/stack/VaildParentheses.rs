struct Solution;

#[derive(Debug, Default)]
struct Info {
    open : char,
    close : char,
    position : i32
}
impl Info{
    fn new() -> Self{ Default::default() }
}

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let info = Info::new();
        for c in s.chars(){
            
        }


        true
    }
}

pub fn run(){
    Solution::is_valid("{}".parse().unwrap());
}