//trie는 tree의 한 종류이다
//보통 Prefix tree digital search tree, retrieval tree라고도 부른다.
//트리의 루트에서부터 자식들을 따라가면서 생성된 문자열들이 trie자료구조에 저장되어나감
use std::collections::HashMap;

#[derive(Default)]
struct Trie {
    is_word: bool,
    children: [Option<Box<Trie>>; 26],
}

impl Trie {
    //data구조 초기화
    fn new() -> Self{
        Default::default()
    }
    fn add_word(&mut self, word : String){
        let mut cur = self;
        for c in word.chars(){
            match &cur.children[c as usize - 'a' as usize] {
                None => cur.children[c as usize - 'a' as usize] = Some(Box::new(Trie::new())),
                Some(n) => ()
            }
            cur = cur.children[c as usize - 'a' as usize].as_mut().unwrap();
        }
        cur.is_word = true;
    }
}

pub fn run(){

}