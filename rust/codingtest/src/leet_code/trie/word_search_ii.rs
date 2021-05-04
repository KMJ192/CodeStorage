use std::collections::HashMap;
struct Solution;

#[derive(Debug)]
struct Trie {
    root: Node
}
impl Trie {
    fn moving<T>(t : T) -> T{
        t
    }
    fn new() -> Self {
        Trie{ root: Node::new() }
    }
    fn insert(&mut self, word: String) {
        let mut current = &mut self.root;
        for w in word.chars(){
            current = Trie::moving(current).next.entry(w).or_insert(Node::new());
        }
        if !current.is_word{
            current.is_word = true;
        }
    }
    fn search(&mut self, word: String) -> bool {
        let mut current = &mut self.root;
        for w in word.chars(){
            if let Some(_) = current.next.get(&w){
                current = Trie::moving(current).next.entry(w).or_insert(Node::new());
            }else{
                return false;
            }
        }
        current.is_word
    }
    fn starts_with(&mut self, prefix: String) -> bool {
        let mut current = &mut self.root;
        for w in prefix.chars(){
            if let Some(_) = current.next.get(&w){
                current = Trie::moving(current).next.entry(w).or_insert(Node::new());
            }else{
                return false;
            }
        }
        true
    }
}

impl Solution {
    pub fn find_words(board: Vec<Vec<char>>, words: Vec<String>) -> Vec<String> {
        let mut answer : Vec<String> = Vec::new();
        let mut words : Vec<String> = Vec::new();
        let mut tmp = String::from("");

        for i in 0..board.len(){
            tmp = "".parse().unwrap();
            for j in board[i].iter(){
                tmp += &*j.to_string();
            }
            words.push(tmp.parse().unwrap());
            tmp = tmp.chars().rev().collect::<String>();
            words.push(tmp.parse().unwrap());
        }

        for i in 0..board[0].len() {
            tmp = "".parse().unwrap();
            for j in 0..board.len(){
                tmp += &*board[j][i].to_string();
            }
            words.push(tmp.parse().unwrap());
            tmp = tmp.chars().rev().collect::<String>();
            words.push(tmp.parse().unwrap());
        }
        println!("{:#?}", words);
        // let mut obj = Trie::new();
        // for i in words.iter(){
        //     obj.insert(i.parse().unwrap());
        // }
        // //println!("{:#?}", obj);
        // println!("{}", obj.starts_with("oath".parse().unwrap()));
        answer
    }
}

#[derive(Debug)]
struct Node{
    is_word: bool,
    next: HashMap<char, Node>
}
impl Node{
    fn new() -> Self {
        Node {
            is_word: false,
            next: HashMap::new()
        }
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
}