#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
  pub val: i32,
  pub left: Option<Rc<RefCell<TreeNode>>>,
  pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
  #[inline]
  pub fn new(val: i32) -> Self {
    TreeNode {
      val,
      left: None,
      right: None
    }
  }
}

use std::rc::Rc; //Reference Counting
use std::cell::RefCell;

struct Solution;
impl Solution {
    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        
        true
    }
}


fn bfs(){

}
fn dfs(){

}

use std::io;
use std::str::FromStr;

pub fn run(){ 
    //let mut root : TreeNode= TreeNode{val : 1, left : None, right: None};
    let mut root : TreeNode;
    let mut tmp : Rc<RefCell<TreeNode>>;
    //root node 입력
    // root = TreeNode{val : 2, left : None, right : None};
    // tmp = Rc::new(RefCell::new(TreeNode{val : 3, left : None, right: None}));
    // root.left = Some(tmp);
    // tmp = Rc::new(RefCell::new(TreeNode{val : 3, left : None, right: None}));
    // root.right = Some(tmp);
    // println!("{:#?}", root.left);
    
    //직접 넣자
    //*를 입력할 때 까지 반복
    //left, right를 각각 입력
    loop{
      let mut node_val = String::new();
      io::stdin().read_line(&mut node_val).expect("error");
      if node_val == "*"{
        break;
      }
      let test : i32 = node_val.parse::<i32>().unwrap();
      //let test : i32 = FromStr::from_str(node_val).unwrap();
      println!("{}", test);
  
    }
    // tmp = Rc::new(RefCell::new(TreeNode{val : 4, left : None, right: None}));
    // root.left = Some(tmp);
    // tmp = Rc::new(RefCell::new(TreeNode{val : 4, left : None, right: None}));
    // root.right = Some(tmp);
    
    //println!("{:#?}", root);
    //Solution::is_symmetric();
  }