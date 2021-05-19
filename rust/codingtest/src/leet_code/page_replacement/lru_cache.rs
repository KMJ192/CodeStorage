use std::rc::Rc;
use std::cell::RefCell;
use std::collections::HashMap;
use std::collections::hash_map::Entry;

#[derive(Debug)]
struct LRUCache {
    capacity: usize,
    link: HashMap<i32, Rc<RefCell<DoublyLinkedListNode<(i32, i32)>>>>,
    list : DoublyLinkedList<(i32, i32)>
}

impl LRUCache {
    fn new(capacity: i32) -> Self {
        LRUCache{
            capacity: capacity as usize,
            link: HashMap::with_capacity(capacity as usize),
            list: DoublyLinkedList::new()
        }
    }
    
    fn get(&mut self, key: i32) -> i32 {
        //key를 찾았을 경우 해당 value를 returm
        match self.link.entry(key){
            Entry::Occupied(mut o) => {
                o.get().borrow().val.1
            }
            _ => -1
        }
    }

    fn put(&mut self, key: i32, value: i32) {
        if self.link.contains_key(&key){
            //같은 key가 있을 경우, 해당 Key에 대한 노드 제거
            self.list.remove(Rc::clone(self.link.get(&key).unwrap()));
        }else if self.capacity == self.list.len(){
            //현재 할당된 크기(list.len())가 최대크기한도(capacity)와 같을 경우, 연결 해제
            if let Some((k, _v)) = self.list.pop_back(){
                self.link.remove(&k);
            }
        }
        //새로운 페이지 할당
        self.link.insert(key, self.list.push_front((key, value)));
    }
}

//이중연결리스트의 node
#[derive(Debug)]
struct DoublyLinkedListNode<T>{
    val : T,
    prev : Option<Rc<RefCell<DoublyLinkedListNode<T>>>>,
    next : Option<Rc<RefCell<DoublyLinkedListNode<T>>>>
}
//이중연결리스트 객체 생성
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
        let new_head = DoublyLinkedListNode::new(val);
        match &self.head.take(){
            Some(old_head) => {
                old_head.borrow_mut().prev = Some(Rc::clone(&new_head));
                new_head.borrow_mut().next = Some(Rc::clone(&old_head));
            },
            _ => {
                self.tail = Some(Rc::clone(&new_head));
            }
        }
        self.head = Some(Rc::clone(&new_head));
        self.length += 1;

        new_head
    }

    fn push_back(&mut self, val: T) -> Rc<RefCell<DoublyLinkedListNode<T>>> {
        let new_tail = DoublyLinkedListNode::new(val);
        match &self.tail.take(){
            Some(old_tail) => {
                old_tail.borrow_mut().next = Some(Rc::clone(&new_tail));
                new_tail.borrow_mut().prev = Some(Rc::clone(&old_tail));
            },
            _=>{
                self.head = Some(Rc::clone(&new_tail));
            }
        }
        self.tail = Some(Rc::clone(&new_tail));
        self.length += 1;

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
                        self.tail = None
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

impl<T> DoublyLinkedListNode<T>{
    fn new(val : T) -> Rc<RefCell<DoublyLinkedListNode<T>>>{
        Rc::new(RefCell::new(DoublyLinkedListNode{
            val,
            prev : None,
            next : None,
        }))
    }
}

// #[derive(Debug)]
// struct Node{
//     key: i32,
//     value: i32,
//     prev: Option<Rc<RefCell<Node>>>,
//     next: Option<Rc<RefCell<Node>>>,
// }
// impl Node{
//     fn new() -> Self{
//         Node{
//             key : 0,
//             value : 0,
//             prev : None,
//             next : None
//         }
//     }
// }

pub fn run(){
    let mut obj = LRUCache::new(4);
    obj.put(1, 1);
    obj.put(2, 2);
    obj.put(3, 3);
    obj.put(4, 4);
    obj.put(5, 5);
    obj.put(1, 3);
    let ret : i32 = obj.get(5);
    println!("{:#?}", ret);

    // let mut f_node = Node::new();
    // let mut s_node = Node::new();
    // let mut t_node = Node::new();
    // let mut temp_node = Node::new();
    // f_node.key = 1;
    // f_node.value = 1;
    //
    // s_node.key = 2;
    // s_node.value = 2;
    //
    // t_node.key = 3;
    // t_node.value = 3;
    //
    // temp_node.key = 0;
    // temp_node.value = 0;
    //
    // f_node.next = Some(Rc::new(RefCell::new(s_node)));
    // f_node.prev = Some(Rc::new(RefCell::new(t_node)));
    //
    //
    // let test = f_node.prev.as_ref().map(|a| Rc::clone(a));
    // println!("{:?}", test);

    // let mut hash = HashMap::new();
    // hash.entry("123").or_insert(1);
    //
    // match hash.entry("123"){
    //     Entry::Occupied(o) => {
    //         println!("{:?}", o.key());
    //         println!("{:?}", o.get());
    //     }
    //     _ => {}
    // }

    // println!("{:?}",hash.entry("123"));
}
