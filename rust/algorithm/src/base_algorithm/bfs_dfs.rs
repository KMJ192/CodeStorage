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
struct Solution;

use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        
        true
    }
}


fn bfs(){

}
fn dfs(){

}
pub fn run(){
    let root = TreeNode{val : 1, left : None, right: None};
    //root.left = TreeNode{val : 2, left : None, right: None};
    
    println!("{:?}", root);
    //Solution::is_symmetric();
}