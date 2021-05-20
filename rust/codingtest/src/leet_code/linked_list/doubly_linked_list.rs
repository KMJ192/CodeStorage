use std::rc::Rc;
use std::cell::RefCell;

//Doubly Linked List Node
#[derive(Debug)]
struct DoublyLinkedListNode<T>{
    prev : Option<Rc<RefCell<DoublyLinkedListNode<T>>>>,
    val : T,
    next : Option<Rc<RefCell<DoublyLinkedListNode<T>>>>
}
impl<T> DoublyLinkedListNode<T>{
    fn new(val : T) -> Rc<RefCell<DoublyLinkedListNode<T>>>{
        Rc::new(RefCell::new(DoublyLinkedListNode{
            prev : None,
            val,
            next : None,
        }))
    }
}
//Doubly Linked List Object
#[derive(Debug)]
struct DoublyLinkedList<T> {
    head: Option<Rc<RefCell<DoublyLinkedListNode<T>>>>,
    tail: Option<Rc<RefCell<DoublyLinkedListNode<T>>>>,
    length: usize
}

//T에 대한 Copy 허용
impl<T> DoublyLinkedList<T> where T: Copy{
    fn new() -> Self{
        DoublyLinkedList{
            head: None,
            tail: None,
            length: 0
        }
    }
    fn len(&self) -> usize{
        self.length
    }

    fn push_front(&mut self, val: T) -> Rc<RefCell<DoublyLinkedListNode<T>>>{
        let new_node = DoublyLinkedListNode::new(val);
        if let Some(old_node) = &self.head.take() {
            new_node.borrow_mut().next = Some(Rc::clone(&old_node));
            old_node.borrow_mut().prev = Some(Rc::clone(&new_node));
        }else{
            self.tail = Some(Rc::clone(&new_node));
        }
        self.head = Some(Rc::clone(&new_node));
        self.length += 1;
        new_node
    }

    fn push_back(&mut self, val: T) -> Rc<RefCell<DoublyLinkedListNode<T>>> {
        let new_tail = DoublyLinkedListNode::new(val);
        new_tail
    }
    fn pop_front(&mut self) -> Option<T>{
        match &self.head.take(){
            Some(head_node) => {
                match head_node.borrow_mut().next.as_mut(){
                    Some(next_node) =>{
                        next_node.borrow_mut().prev = None;
                        self.head = Some(Rc::clone(&next_node));
                    },
                    _ =>{
                        self.tail = None;
                    }
                }
                self.length -= 1;
                Some(head_node.borrow().val)
            },
            _ => None
        }
    }

    //back노드 연결 해제
    fn pop_back(&mut self) -> Option<T>{
        match &self.tail.take() {
            Some(tail_node) => {
                match tail_node.borrow_mut().prev.as_mut(){
                    Some(prev_node) => {
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

    fn remove(&mut self, node: Rc<RefCell<DoublyLinkedListNode<T>>>) -> T{
        if node.borrow().prev.is_none() && node.borrow().next.is_none(){
            self.head = None;
            self.tail = None;
            self.length = 0;

            return node.borrow().val;
        }
        let mut rn = node.borrow_mut();
        match rn.prev.take() {
            Some(prev_node) => {
                match rn.next.take(){
                    Some(next_node) => {
                        prev_node.borrow_mut().next = Some(Rc::clone(&next_node));
                        next_node.borrow_mut().prev = Some(prev_node);
                    },
                    _ => {
                        prev_node.borrow_mut().next = None;
                        self.tail = Some(prev_node);
                    }
                }
            },
            _ => {
                self.head = rn.next.clone();
                self.head.as_mut().unwrap().borrow_mut().prev = None;
            }
        }
        self.length -= 1;
        rn.val
    }
}

pub fn run(){
    let mut t : DoublyLinkedList<i32> = DoublyLinkedList::new();
    t.push_front(1);
    t.push_front(2);
    println!("Doubly Linked List : {:#?} ", t.head);
}