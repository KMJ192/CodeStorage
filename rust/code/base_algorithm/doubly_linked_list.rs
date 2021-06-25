use std::rc::Rc;
use std::cell::RefCell;

#[derive(Debug)]
struct Node<T>{
    val: T,
    prev: Option<Rc<RefCell<Node<T>>>>,
    next: Option<Rc<RefCell<Node<T>>>>
}
impl<T> Node<T>{
    fn new(val : T) -> Rc<RefCell<Node<T>>>{
        Rc::new(RefCell::new(Node{
            val,
            prev : None,
            next : None,
        }))
    }
}

#[derive(Debug)]
struct DoublyLinkedList<T>{
    head: Option<Rc<RefCell<Node<T>>>>,
    tail: Option<Rc<RefCell<Node<T>>>>,
    length: usize
}

impl<T> DoublyLinkedList<T> where T: Copy{
    fn new() -> Self{
        DoublyLinkedList{
            head: None,
            tail: None,
            length: 0
        }
    }
    fn len(&self) -> usize {
        self.length
    }

    fn push_front(&mut self, val: T) -> Rc<RefCell<Node<T>>> {
        let new_head = Node::new(val);
        match &self.tail.take(){
            Some(old_head) => {
                old_head.borrow_mut().next = Some(Rc::clone(&new_head));
                new_head.borrow_mut().prev = Some(Rc::clone(&old_head));
            },
            _=>{
                self.tail = Some(Rc::clone(&new_head));
            }
        }
        self.head = Some(Rc::clone(&new_head));
        self.length += 1;

        new_head
    }
    fn push_back(&mut self, val: T) -> Rc<RefCell<Node<T>>> {
        let new_tail = Node::new(val);
        match &self.tail.take(){
            Some(old_tail) => {
                old_tail.borrow_mut().next = Some(Rc::clone(&new_tail));
                new_tail.borrow_mut().prev = Some(Rc::clone(&old_tail));
            }
            _ => {
                self.head = Some(Rc::clone(&new_tail));
            }
        }
        self.tail = Some(Rc::clone(&new_tail));
        self.length += 1;
        new_tail
    }
    fn pop_front(&mut self) -> Option<T> {
        match &self.head.take(){
            Some(head_node) => {
                match head_node.borrow_mut().next.as_mut() {
                    Some(next_node) => {
                        //head node와 next node 연결 해제
                        next_node.borrow_mut().prev = None;
                        //현재 head를 next node와 연결
                        self.head = Some(Rc::clone(&next_node));
                    },
                    _ => {
                        self.tail = None
                    }
                }
                self.length -= 1;
                Some(head_node.borrow().val)
            },
            _ => None
        }
    }
    fn pop_back(&mut self) -> Option<T>{
        match &self.tail.take(){
            Some(tail_node) => {
                match tail_node.borrow_mut().prev.as_mut(){
                    Some(prev_node)=> {
                        prev_node.borrow_mut().next = None;
                        self.tail = Some(Rc::clone(&prev_node));
                    },
                    _ => {
                        self.head = None;
                    }
                }
                self.length -= 1;
                Some(tail_node.borrow().val)
            },
            _ => None
        }
    }
}

pub fn run(){
    let mut tmp = DoublyLinkedList::new();
    tmp.push_front(1);
    tmp.push_front(2);
    tmp.push_front(3);

    match tmp.head.take(){
        Some(node) => {
            println!("{}", node.borrow().val)
        },
        _ => println!("None")
    }
}