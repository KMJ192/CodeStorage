//trie는 tree의 한 종류이다
//보통 Prefix tree digital search tree, retrieval tree라고도 부른다.
//트리의 루트에서부터 자식들을 따라가면서 생성된 문자열들이 trie자료구조에 저장되어나감

use std::collections::HashMap;
use std::hash::Hash;

#[derive(Debug)]
struct Trie{
    root : HashMap<char, Vec<String>>,
    end : String
}
impl Trie{
    fn add_word(self, word : String){
        let mut current_node = &self.root;
        println!("{:#?}", current_node);
        for i in word.chars(){
            let cur_char = i;
            println!("{}",current_node.contains_key(&cur_char));
            if !current_node.contains_key(&cur_char) {
                current_node = current_node.
            }
        }
    }
    fn search_word(self){

    }
    fn show(){

    }
}

fn build_trie(words : Trie, dictionary : HashMap<String, i32>){

}
pub fn run(){
    let root_node : HashMap<char, Vec<String>> = HashMap::new();
    let mut trie1 = Trie{
        root : root_node,
        end : "*".parse().unwrap()
    };
    // let mut words: Vec<String> = Vec::new();
    // words.push("apple".parse().unwrap());
    // words.push("cat".parse().unwrap());
    // words.push("dog".parse().unwrap());
    // words.push("plane".parse().unwrap());
    // words.push("bottle".parse().unwrap());
    // words.push("note".parse().unwrap());
    // words.push("computer".parse().unwrap());

    Trie::add_word(trie1, ("bottle").parse().unwrap());
}