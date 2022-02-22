#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

struct Solution;

use std::cmp::Ordering;
use std::collections::BinaryHeap;

// 정렬 순서에 대한 비교하는 트레잇
impl PartialOrd<ListNode> for ListNode {
  // self와 order 사이의 값을 반환
  fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
    other.val.partial_cmp(&self.val)
  }
}

// 전체 순서를 형성
impl Ord for ListNode {
  // Ordering 사이를 반환
  fn cmp(&self, other: &Self) -> Ordering {
    other.val.cmp(&self.val)
  }
}

impl Solution {
  pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
    let mut res = Box::new(ListNode::new(0));
    if lists.len() == 0 {
      return None;
    }
    let mut min_heap = BinaryHeap::new();
    for mut list in lists {
      // None이아닌 Some의 값이면 true를 반환
      if list.is_some() {
        min_heap.push(list.take()?);
      }
    }

    let mut cur = &mut res;
    while !min_heap.is_empty() {
      cur.next = min_heap.pop();
      cur = cur.next.as_mut()?;
      if cur.next.is_some() {
        min_heap.push(cur.next.take()?);
      }
    }
    res.next
  }
}

pub fn run() {
  let mut list1 = ListNode::new(1);
  list1.next = Some(Box::new(ListNode::new(4)));
  if let Some(ref mut list) = list1.next {
    list.next = Some(Box::new(ListNode::new(5)));
  };

  let mut list2 = ListNode::new(1);
  list2.next = Some(Box::new(ListNode::new(3)));
  if let Some(ref mut list) = list2.next {
    list.next = Some(Box::new(ListNode::new(4)));
  };

  let mut list3 = ListNode::new(2);
  list3.next = Some(Box::new(ListNode::new(6)));
  
  let lists = vec![
    Some(Box::new(list1)),
    Some(Box::new(list2)),
    Some(Box::new(list3))
  ];
  println!("{:?}", Solution::merge_k_lists(lists));
}