struct Solution;
impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut s_sort : Vec<char>= s.chars().collect();
        let mut t_sort : Vec<char>= t.chars().collect();
        s_sort.sort();
        t_sort.sort();
        if s_sort == t_sort{
            return true;
        }
        false
    }
}

pub fn run(){
    println!("{}", Solution::is_anagram("anagram".parse().unwrap(), "nagaram".parse().unwrap()));
}