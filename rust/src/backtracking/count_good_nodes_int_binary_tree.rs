use std::rc::Rc;
use std::cell::RefCell;
use std::cmp::max;

// Definition for a binary tree node.
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

impl Solution {
    pub fn good_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max_so_far = None;
        let mut count = 0;
        Solution::recursion(&root, max_so_far, &mut count)
    }

    fn recursion(root: &Option<Rc<RefCell<TreeNode>>>, max_so_far: Option<i32>, count: &mut i32) -> i32 {
        if let Some(node) = root {
            let mut new_max = max_so_far.unwrap_or(node.borrow().val);

            if node.borrow().val >= new_max {
                *count += 1;
            }

            new_max = new_max.max(node.borrow().val);
            Solution::recursion(&node.borrow().left, Some(new_max), count);
            Solution::recursion(&node.borrow().right, Some(new_max), count);
        }
        *count
    }
}

pub fn run() {
    let mut root: Option<Rc<RefCell<TreeNode>>> = Some(Rc::new(RefCell::new(TreeNode::new(3))));

    if let Some(ref mut root) = root {
        let mut l: Option<Rc<RefCell<TreeNode>>> = Some(Rc::new(RefCell::new(TreeNode::new(1))));
        let mut r: Option<Rc<RefCell<TreeNode>>> = Some(Rc::new(RefCell::new(TreeNode::new(4))));

        if let Some(ref mut l) = l {
            let ll: Option<Rc<RefCell<TreeNode>>> = Some(Rc::new(RefCell::new(TreeNode::new(3))));
            l.borrow_mut().left = ll;
        }

        if let Some(ref mut r) = r {
            let rl: Option<Rc<RefCell<TreeNode>>> = Some(Rc::new(RefCell::new(TreeNode::new(1))));
            let rr: Option<Rc<RefCell<TreeNode>>> = Some(Rc::new(RefCell::new(TreeNode::new(5))));

            r.borrow_mut().left = rl;
            r.borrow_mut().right = rr;
        }

        root.borrow_mut().left = l;
        root.borrow_mut().right = r;
    }

    println!("{}", Solution::good_nodes(root));

}