/*
    input
     - 문자열 배열 ["mobile","mouse","moneypot","monitor","mousepad"]
     - 문자열 "mounse"
    output
     - 2차원 배열
     [
        ["mobile","moneypot","monitor"],
        ["mobile","moneypot","monitor"],
        ["mouse","mousepad"],
        ["mouse","mousepad"],
        ["mouse","mousepad"]
    ]


*/

struct Solution;
impl Solution {
    pub fn suggested_products(products: Vec<String>, search_word: String) -> Vec<Vec<String>> {
        let answer = vec![];

        answer
    }
}

pub fn run(){
    let products = vec![
        String::from("mobile"),
        String::from("mouse"),
        String::from("moneypot"),
        String::from("monitor"),
        String::from("mousepad")
    ];
    let search_word = String::from("mouse");
    let result = Solution::suggested_products(products, search_word);
    println!("{:?}", result);
}