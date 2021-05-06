// use std::collections::HashMap;
//
// #[derive(Default)]
// #[derive(Debug)]
// struct Trie{
//     is_end: bool,
//     pos_x : i32,
//     pos_y : i32,
//     next : HashMap<char, Trie>
// }
// impl Trie{
//     fn new() -> Self{
//         Default::default()
//     }
//     fn insert(&mut self, word: String){
//         let mut curr = self;
//         for c in word.chars(){
//             curr = curr.next.entry(c).or_insert(Trie::new());
//         }
//         curr.is_end = true;
//     }
// }

#[derive(Default)]
struct Position{
    x : usize,
    y : usize,
    visited : [usize; 26]
}
impl Position{
    fn new() -> Self{
        Default::default()
    }
}

struct Solution;

use std::collections::VecDeque;
impl Solution {
    pub fn find_words(board: Vec<Vec<char>>, words: Vec<String>) -> Vec<String> {
        let mut answer : Vec<String> = Vec::new();
        let mut pos = Position::new();
        println!("{:?}", board);
        pos.x = 0;
        pos.y = 0;
        for i in words.iter(){
            if Solution::search(&board, i.parse().unwrap(), &pos){
                answer.push(i.parse().unwrap());
            }
            println!();
        }
        answer
    }
    fn search(board : &Vec<Vec<char>>, word : String, pos : &Position) -> bool{
        let mut queue = VecDeque::new();
        let tmp = &word[0..1];
        for i in 0..board.len() {
            for j in 0..board[i].len(){
                if board[i][j] == tmp.parse().unwrap() {
                    queue.push_back((i, j));
                }
            }
        }
        if queue.is_empty() {
            return false;
        }
        let (mut x, mut y) = queue.pop_front().unwrap();
        //상하좌우 검사
        //상 y-1
        if y > 0 {

        }
        //하 y+1

        //좌 x-1

        //우 x+1


        true
    }
    fn find(x : usize, y : usize){

    }
}

pub fn run(){
    let board: Vec<Vec<char>> = vec![
        vec!["o".parse().unwrap(),"a".parse().unwrap(),"a".parse().unwrap(),"n".parse().unwrap()],
        vec!["e".parse().unwrap(),"t".parse().unwrap(),"a".parse().unwrap(),"e".parse().unwrap()],
        vec!["i".parse().unwrap(),"h".parse().unwrap(),"k".parse().unwrap(),"r".parse().unwrap()],
        vec!["i".parse().unwrap(),"f".parse().unwrap(),"l".parse().unwrap(),"v".parse().unwrap()],
    ];
    let words : Vec<String>= vec![
        "oath".parse().unwrap(),
        "pea".parse().unwrap(),
        "eat".parse().unwrap(),
        "rain".parse().unwrap()
    ];
    Solution::find_words(board, words);
    // let mut obj = Trie::new();
    // obj.insert("word".parse().unwrap());
    // println!("{:#?}", obj);
}