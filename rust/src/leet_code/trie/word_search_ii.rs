struct Solution;
use std::collections::HashMap;

#[derive(Default, Debug)]
struct Trie{
    node : HashMap<char, Trie>,
    word : String
}

impl Trie{
    fn new() -> Self{
        Default::default()
    }
    fn insert(&mut self, words: &Vec<String>){
        for word in words.iter(){
            let mut current_node = &mut *self;
            for c in word.chars(){
                //node의 hashmap에서 c가 없으면 hashmap에 Node를 insert
                current_node = current_node.node.entry(c).or_insert(Trie::new());
            }
            current_node.word = word.parse().unwrap();
        }
    }
}

//Time complexity => O(n * m)
impl Solution{
    pub fn find_words(board : Vec<Vec<char>>, words : Vec<String>) -> Vec<String>{
        let mut answer:Vec<String> = Vec::new();
        let mut trie = Trie::new();
        trie.insert(&words);

        let mut visited = board.clone();
        println!("{:#?}", trie);

        //2차원 배열 전체를 확인하기 위해
        for x in 0..visited.len() {
            for y in 0..visited[x].len() {
                Self::search_position(&mut visited, &mut answer, &mut trie, x, y);
            }
        }
        println!("{:?}", answer);
        answer
    }
    fn search_position(mut visited : &mut Vec<Vec<char>>, answer : &mut Vec<String>, trie : &mut Trie, x: usize, y: usize) {

        if visited[x][y] == '0' { return; } //방문한 노드일 경우 returm
        let c = visited[x][y];
        //println!("{:?} {}", trie, c);
        let next = &mut trie.node;
        if !next.contains_key(&c) {
            //현재 position에 대하여 찾아야되는 character가 아닐 경우 종료
            return;
        }

        //현재 Node
        let mut next_trie = next.get_mut(&c).unwrap();

        //찾고자하는 문자열에 도달했을 경우
        if next_trie.word != "".parse::<String>().unwrap() {
            answer.push(next_trie.word.parse().unwrap());
            next_trie.word = "".parse().unwrap(); //중복 탐색을 피하기 위해 None으로 변경
        }

        //현재 loop에서 방문 표시
        visited[x][y] = '0';

        //left check
        if x > 0 {
            Self::search_position(&mut visited, answer, next_trie, x - 1, y);
        }
        //rigth check
        if x < visited.len() - 1 {
            Self::search_position(&mut visited, answer, next_trie, x + 1, y);
        }
        //top check
        if y < visited[0].len() - 1 {
            Self::search_position(&mut visited, answer, next_trie, x, y + 1);
        }
        //bottom check
        if y > 0 {
            Self::search_position(&mut visited, answer, next_trie, x, y - 1);
        }

        //현재 loop 종료 다시 되돌려놓음
        visited[x][y] = c;
    }
}

// impl Trie{
//     fn extract_type<T>(t : T) -> T{
//         t
//     }
//     fn new() -> Self{
//         Default::default()
//     }
//     fn insert(&mut self, words: &Vec<String>){
//         for word in words.iter(){
//             let mut current_node = &mut *self;
//             for c in word.chars(){
//                 //node의 hashmap에서 c가 없으면 hashmap에 Node를 insert
//                 current_node = current_node.next.entry(c).or_insert(Trie::new());
//             }
//             current_node.word = Some(word.parse().unwrap());
//         }
//     }
// }
//
// //Time complexity => O(n * m)
// impl Solution{
//     pub fn find_words(board : Vec<Vec<char>>, words : Vec<String>) -> Vec<String>{
//         let mut answer:Vec<String> = Vec::new();
//         let mut trie = Trie::new();
//         trie.insert(&words);
//         println!("{:#?}", trie);
//         let mut visited = board.clone();
//
//         //2차원 배열 전체를 확인하기 위해
//         for x in 0..visited.len() {
//             for y in 0..visited[x].len() {
//                 Self::search_position(&mut visited, &mut answer, &mut trie, x, y);
//             }
//         }
//
//         println!("{:?}", answer);
//         answer
//     }
//     fn search_position(mut visited : &mut Vec<Vec<char>>, answer : &mut Vec<String>, trie : &mut Trie, x: usize, y: usize) {
//         if visited[x][y] == '0' { return; } //방문한 노드일 경우 returm
//         let mut c = visited[x][y];
//         println!("{:?} {}", trie, c);
//         let mut next = &mut trie.node;
//         if !next.contains_key(&c) { return; } //찾아야되는 character가 아닐 경우 종료
//
//         //현재 Node
//         let mut next_trie = next.get_mut(&c).unwrap();
//
//         //찾고자하는 문자열에 도달했을 경우
//         if let Some(word) = &next_trie.word {
//             println!("{:?}", next_trie.word);
//             answer.push(word.to_string());
//             next_trie.word = None; //중복 탐색을 피하기 위해 None으로 변경
//         }
//
//         //현재 loop에서 방문 표시
//         visited[x][y] = '0';
//
//         //left check
//         if x > 0 {
//             Self::search_position(&mut visited, answer, next_trie, x - 1, y);
//         }
//         //bottom check
//         if y > 0 {
//             Self::search_position(&mut visited, answer, next_trie, x, y - 1);
//         }
//         //rigth check
//         if x < visited.len() - 1 {
//             Self::search_position(&mut visited, answer, next_trie, x + 1, y);
//         }
//         //top check
//         if y < visited[0].len() - 1 {
//             Self::search_position(&mut visited, answer, next_trie, x, y + 1);
//         }
//
//         //현재 loop 종료 다시 되돌려놓음
//         visited[x][y] = c;
//     }
// }

pub fn run(){
    // let board: Vec<Vec<char>> = vec![
    //     vec!['o','a','a','n'],
    //     vec!['e','t','a','e'],
    //     vec!['i','h','k','r'],
    //     vec!['i','f','l','v'],
    // ];
    // let words : Vec<String>= vec![
    //     "oath".parse().unwrap(),
    //     "pea".parse().unwrap(),
    //     "eat".parse().unwrap(),
    //     "rain".parse().unwrap()
    // ];
    let board: Vec<Vec<char>> = vec![
        vec!['a'],
        vec!['a'],
        vec!['a']
    ];
    let words : Vec<String>= vec![
        "aaa".parse().unwrap()
    ];
    // let mut board = vec![
    //     vec!['b', 'a', 'h'],
    //     vec!['a', 'n', 'h'],
    //     vec!['n', 'h', 'h'],
    //     vec!['a', 'h', 'h'],
    //     vec!['x', 'h', 'h']
    // ];
    // let words : Vec<String>= vec![
    //     "banax".parse().unwrap(),
    // ];
    // let mut board = vec![
    //     vec!['o','a','b','n'],
    //     vec!['a','t','a','e'],
    //     vec!['a','h','k','r'],
    //     vec!['s','f','l','v']
    // ];
    // let words : Vec<String> = vec![
    //     "oa".parse().unwrap(),
    //     "oaa".parse().unwrap()
    // ];

    Solution::find_words(board, words);
}