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

enum List{
  Cons(i32, Rc<List>),
  Nil,
}
use List::{Cons, Nil};

pub fn run(){ 
  //let mut root : Option<Rc<RefCell<TreeNode>>>;
  //let mut tmp : Rc<RefCell<TreeNode>>;
  //root node 입력
  //tmp = Rc::new(RefCell::new(TreeNode{val : 1, left : None, right: None}));
  //Solution::is_symmetric();

  let a = Rc::new(Cons(5, Rc::new(Cons(10, Rc::new(Nil)))));
  println!("{}", Rc::strong_count(&a));
  let b = Cons(3, Rc::clone(&a));
  println!("{}", Rc::strong_count(&a));
  let c = Cons(2, Rc::clone(&a));
  println!("{}", Rc::strong_count(&a));
}

pub trait Messenger {
  fn send(&self, msg: &str);
}

pub struct LimitTracker<'a, T: 'a + Messenger> {
  messenger: &'a T,
  value: usize,
  max: usize,
}

impl<'a, T> LimitTracker<'a, T>
  where T: Messenger {
  pub fn new(messenger: &T, max: usize) -> LimitTracker<T> {
      LimitTracker {
          messenger,
          value: 0,
          max,
      }
  }

  pub fn set_value(&mut self, value: usize) {
      self.value = value;

      let percentage_of_max = self.value as f64 / self.max as f64;

      if percentage_of_max >= 0.75 && percentage_of_max < 0.9 {
          self.messenger.send("Warning: You've used up over 75% of your quota!");
      } else if percentage_of_max >= 0.9 && percentage_of_max < 1.0 {
          self.messenger.send("Urgent warning: You've used up over 90% of your quota!");
      } else if percentage_of_max >= 1.0 {
          self.messenger.send("Error: You are over your quota!");
      }
  }
}