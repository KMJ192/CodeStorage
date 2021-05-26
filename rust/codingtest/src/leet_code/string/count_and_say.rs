struct Solution;

impl Solution {
    pub fn count_and_say(n: i32) -> String {

        fn countnsay(n: i32) -> String {
            if n == 1 {
                return 1.to_string();
            }
            let n = countnsay(n - 1);
            let mut s = n.chars().fold(
                ("".to_string(), '&', 0),
                |(mut done, in_prog, count), char| {
                    match char == in_prog {
                        true => (done, in_prog, count + 1),
                        false if in_prog != '&' => (format!("{}{}{}", done, count, in_prog), char, 1),
                        _ => (done, char, 1),
                    }
                },
            );
            format!("{}{}{}", s.0, s.2, s.1)
        }

        countnsay(n)
    }
}

pub fn run(){
    println!("{}", Solution::count_and_say(4));
}