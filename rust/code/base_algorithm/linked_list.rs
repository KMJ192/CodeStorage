use std::collections::HashSet;
use std::iter::FromIterator;
use std::borrow::BorrowMut;

struct Solution;

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode where i32 : Copy {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

impl Solution {
    pub fn num_components(head: Option<Box<ListNode>>, nums: Vec<i32>) -> i32 {
        let mut h = head;
        let mut set_num: HashSet<i32> = HashSet::from_iter(nums);

        let mut res = 0;
        while let Some(cur) = h {
            if set_num.contains(&cur.val)
                && cur.next.is_none()
                || !set_num.contains(&cur.next.as_ref().unwrap().val){
                res += 1;
            }
            h = cur.next;
        }
        res
    }
}

pub fn run(){
    let mut node = Some(Box::new(ListNode{
        val:0,
        next: Some(Box::new(ListNode{
            val: 1,
            next: Some(Box::new(ListNode{
                val: 2,
                next: None
            }))
        }))
    }));

    // for i in 0..2{
    //     let mut tmp = node.take().borrow_mut();
    //     println!("{:?}", tmp.val);
    //     tmp = node.take().borrow_mut().next;
    // }


}