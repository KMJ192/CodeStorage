

fn bfs(){

}

fn dfs(){

}

use std::io;

pub fn run(){
  let test = [
    [1, 1]
  ];
  let mut graph : Vec<Vec<i32>> = Vec::new();
  let mut str = String::new();
  //정점의 개수, 간선의 개수, 정점의 번호
  io::stdin().read_line(&mut str).expect("error");
  let n : i32 = str.parse::<i32>().unwrap();

  str = "".to_string();
  io::stdin().read_line(&mut str).expect("error");
  let m : i32 = str.parse::<i32>().unwrap();

  str = "".to_string();
  io::stdin().read_line(&mut str).expect("error");
  let v : i32 = str.parse::<i32>().unwrap();

    for i in 0..m {
      str = "".to_string();
      io::stdin().read_line(&mut str).expect("error");
      let x : i32 = str.parse::<i32>().unwrap();
      str = "".to_string();
      io::stdin().read_line(&mut str).expect("error");
      let y : i32 = str.parse::<i32>().unwrap();

    }    
}