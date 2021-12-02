use std::collections::HashMap;

#[derive(Debug)]
struct Trie{
    next: HashMap<char, Trie>,
    word: String
}
impl Trie{
    fn new() -> Self{
        let n = HashMap::new();
        Trie{
            next: n,
            word: String::from("")
        }
    }
    fn insert(&mut self, words: &Vec<String>){
        for i in 0..words.len(){
            let mut current_node = &mut *self;
            for c in words[i].chars(){
                current_node = current_node.next.entry(c).or_insert(Trie::new());
            }
            current_node.word = words[i].parse().unwrap();
        }
    }
}

struct Solution;
impl Solution {
    pub fn longest_word(words: Vec<String>) -> String {
        // if words.len() == 0 { return String::from(""); }
        // if words.len() == 1 { return String::from(&words[0]); }
        //
        // let mut trie = Trie::new();
        // trie.insert(&words);
        //
        // //println!("{:#?}", trie);
        //
        // let mut text_bundle: Vec<&String> = vec![];
        // let mut curr_word = vec![];
        //
        // let mut pointer: usize = 0;
        //
        // for (_, value) in &trie.next{
        //     curr_word.push(value);
        // }
        //
        // for i in 0..curr_word.len(){
        //     let mut curr_trie = curr_word[i];
        //     for j in 0..words.len(){
        //         let mut tmp = vec![];
        //         for (key, _) in &curr_trie.next{
        //             tmp.push(key);
        //         }
        //         let mut prev = curr_trie;
        //         for n in 0..tmp.len(){
        //             if tmp.len() > 1{
        //                 curr_trie = &prev.next[&tmp[n]];
        //             }else{
        //                 curr_trie = &curr_trie.next[&tmp[n]];
        //             }
        //             if curr_trie.next.is_empty() {
        //                 if text_bundle.len() == 0 {
        //                     text_bundle.push(&curr_trie.word);
        //                     println!("{:?}", text_bundle);
        //                 }else{
        //                     if text_bundle[pointer].len() < curr_trie.word.len(){
        //                         text_bundle[pointer] = &curr_trie.word;
        //                     } else if text_bundle[pointer].len() == curr_trie.word.len(){
        //                         text_bundle.push(&curr_trie.word);
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
        // println!("{:?}", text_bundle);
        // text_bundle.sort();
        // println!("{:?}", text_bundle);
        // String::from(text_bundle[text_bundle.len() - 1])
        let mut words_length = HashMap::new();
        words.iter().for_each(|word|
            words_length.entry(word.len()).or_insert(vec![]).push(word)
        );
        println!("hashmap = {:?}", words_length);
        let mut candidates = words_length.get(&1usize).unwrap_or(&vec![]).clone();
        println!("initial word = {:?}", candidates);
        for len in 2usize..{
            if let Some(words) = words_length.get(&len){
                let mut new_candidates = Vec::new();
                for &word in words {
                    for &candidate in &candidates {
                        if word.starts_with(candidate){
                            new_candidates.push(word);
                            break;
                        }
                    }
                }
                if new_candidates.is_empty(){
                    break;
                }
                candidates = new_candidates;
            }else{
                break;
            }
        }
        candidates.sort();
        if let Some(&word) = candidates.iter().next(){
            word.clone()
        }else{
            String::from("")
        }
    }
}

pub fn run(){
    let mut words = vec![
        String::from("w"),
        String::from("wo"),
        String::from("wor"),
        String::from("worl"),
        String::from("world"),
        String::from("a"),
        String::from("ap"),
        String::from("app"),
        String::from("appl"),
        String::from("apple"),
    ];

    // let mut words = vec![
    //     String::from("a"),
    //     String::from("ap"),
    //     String::from("app"),
    //     String::from("appl"),
    //     String::from("apple"),
    //     String::from("apply"),
    //     String::from("banana"),
    // ];

    // let mut words = vec![
    //     String::from("yo"),
    //     String::from("ew"),
    //     String::from("fc"),
    //     String::from("zrc"),
    //     String::from("yodn"),
    //     String::from("fcm"),
    //     String::from("qm"),
    //     String::from("qmo"),
    //     String::from("fcmz"),
    //     String::from("z"),
    //     String::from("ewq"),
    //     String::from("yod"),
    //     String::from("ewqz"),
    //     String::from("y")
    // ];

    println!("{}", Solution::longest_word(words));
}