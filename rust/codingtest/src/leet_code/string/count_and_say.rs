struct Solution;

// impl Solution {
//     pub fn count_and_say(n: i32) -> String {
//
//         fn countnsay(n: i32) -> String {
//             if n == 1 {
//                 return 1.to_string();
//             }
//             let n = countnsay(n - 1);
//             let mut s = n.chars().fold(
//                 ("".to_string(), '&', 0),
//                 |(mut done, in_prog, count), char| {
//                     match char == in_prog {
//                         true => (done, in_prog, count + 1),
//                         false if in_prog != '&' => (format!("{}{}{}", done, count, in_prog), char, 1),
//                         _ => (done, char, 1),
//                     }
//                 },
//             );
//             format!("{}{}{}", s.0, s.2, s.1)
//         }
//
//         countnsay(n)
//     }
// }

impl Solution {
    pub fn count_and_say(n: i32) -> String {
        let base = "1";
        Self::produce_next(1, n, base.to_string())
    }

    fn produce_next(current: i32, end: i32, str: String) -> String {
        if current == end {
            return str;
        }
        let mut prev : char = ' ';
        let mut freq : i32 = 0;
        let mut result = String::from("");
        for ch in str.chars() {
            if prev == ' ' {
                prev = ch;
                freq += 1;
            } else if ch == prev {
                freq += 1;
            } else {
                result.push_str(&format!("{}{}", freq, prev));
                prev = ch;
                freq = 1;
            };
        }

        result.push_str(&format!("{}{}", freq, prev));
        Self::produce_next(current + 1, end, result)
    }
}

pub fn run(){
    println!("{}", Solution::count_and_say(4));
}