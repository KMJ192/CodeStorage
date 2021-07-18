/*
    input
     - 문자열 배열 products ["mobile","mouse","moneypot","monitor","mousepad"]
     - 문자열 search_word "mounse"
    output
     - 2차원 배열
     [
        ["mobile","moneypot","monitor"],
        ["mobile","moneypot","monitor"],
        ["mouse","mousepad"],
        ["mouse","mousepad"],
        ["mouse","mousepad"]
    ]
    search_word의 문자 하나하나 입력될 때 마다 미리보기 보여주기
*/
struct Solution;
impl Solution {
    pub fn suggested_products(mut products: Vec<String>, search_word: String) -> Vec<Vec<String>> {
        products.sort();
        let s = search_word.as_bytes();
        println!("{:?}", s);
        let mut answer = vec![Vec::new(); s.len()];
        for product in &products{
            let p = product.as_bytes();
            let mut i = 0;
            while i < p.len().min(s.len()) && p[i] == s[i] {
                if answer[i].len() < 3{
                    answer[i].push(product.clone());
                }
                i += 1;
            }
        }
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
    // let tmp = products.as_slice();
    // println!("{}", tmp[0]);
}