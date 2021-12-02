use std::collections::HashMap;

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

pub fn run(){
    let mut obj = Trie::new();
    obj.insert("apple".parse().unwrap());
    obj.insert("cat".parse().unwrap());
    obj.insert("dog".parse().unwrap());
    obj.insert("boat".parse().unwrap());
    obj.insert("plane".parse().unwrap());
    obj.insert("bottle".parse().unwrap());
    obj.insert("note".parse().unwrap());
    obj.insert("compiler".parse().unwrap());
    // let ret_2: bool = obj.search("apple".parse().unwrap());
    // let ret_3: bool = obj.starts_with("app".parse().unwrap());
    // println!("{:?}", ret_2);
    // println!("{:?}", ret_3);
    println!("{:#?}", obj);
}