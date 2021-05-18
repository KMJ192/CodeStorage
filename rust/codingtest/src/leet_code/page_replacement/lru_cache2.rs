use std::rc::Rc;
use std::cell::RefCell;

struct Node{
    key: i32,
    value: i32,
    prev: Option<Rc<RefCell<Node>>>,
    next: Option<Rc<RefCell<Node>>>
}

#[derive(Default)]
struct LinkedList{
    head: Option<Rc<RefCell<Node>>>,
    tail: Option<Rc<RefCell<Node>>>
}

impl LinkedList{
    fn new() -> LinkedList {
        Default::default()
    }
}


pub fn run(){

}