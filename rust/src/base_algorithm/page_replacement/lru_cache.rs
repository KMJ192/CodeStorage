// 릿코드 문제
// https://leetcode.com/problems/lru-cache

use std::rc::Rc;
use std::cell::RefCell;
use std::collections::HashMap;
use std::collections::hash_map::Entry;

#[derive(Debug)]
struct DoublyLinkedListNode<T> {
    val: T,
    prev: Option<Rc<RefCell<DoublyLinkedListNode<T>>>>,
    next: Option<Rc<RefCell<DoublyLinkedListNode<T>>>>,
}

impl<T> DoublyLinkedListNode<T> {
    fn new(val: T) -> Rc<RefCell<DoublyLinkedListNode<T>>> {
        Rc::new(RefCell::new(DoublyLinkedListNode {
            val,
            prev: None,
            next: None,
        }))
    }
}

#[derive(Debug)]
struct DoublyLinkedList<T> {
    head: Option<Rc<RefCell<DoublyLinkedListNode<T>>>>,
    tail: Option<Rc<RefCell<DoublyLinkedListNode<T>>>>,
    length: usize
}

impl<T> DoublyLinkedList<T> where T: Copy {
    fn new() -> Self{
        DoublyLinkedList {
            head: None,
            tail: None,
            length: 0,
        }
    }
    fn len(&self) -> usize {
        self.length
    }

    fn push_front(&mut self, val: T) -> Rc<RefCell<DoublyLinkedListNode<T>>> {
        let new_head = DoublyLinkedListNode::new(val);

        match &self.head.take() {
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

    fn push_back(&mut self, val: T) -> Rc::<RefCell<DoublyLinkedListNode<T>>> {
        let new_tail = DoublyLinkedListNode::new(val);

        match &self.tail.take() {
            Some(old_tail) => {
                old_tail.borrow_mut().next = Some(Rc::clone(&new_tail));
                new_tail.borrow_mut().prev = Some(Rc::clone(&old_tail));
            },
            _ => {
                self.head = Some(Rc::clone(&new_tail));
            }
        }
        self.tail = Some(Rc::clone(&new_tail));
        self.length += 1;

        new_tail
    }

    fn pop_front(&mut self) -> Option<T> {
        match &self.head.take() {
            Some(head_node) => {
                match head_node.borrow_mut().next.as_mut() {
                    Some(next_node) => {
                        next_node.borrow_mut().prev = None;
                        self.head = Some(Rc::clone(&next_node));
                    },
                    _ => {
                        self.tail = None;
                    }
                }
                self.length -= 1;
                Some(head_node.borrow().val)
            },
            _ => {
                None
            }
        }
    }

    fn pop_back(&mut self) ->  Option<T> {
        match &self.tail.take() {
            Some(tail_node) => {
                match tail_node.borrow_mut().prev.as_mut() {
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
            _ => {
              None
            },
        }
    }

    fn remove(&mut self, node: Rc<RefCell<DoublyLinkedListNode<T>>>) -> T {
        if node.borrow().prev.is_none() && node.borrow().next.is_none() {
            self.head = None;
            self.tail = None;
            self.length = 0;

            return node.borrow().val;
        }
        let mut rn = node.borrow_mut();
        match rn.prev.take() {
            Some(prev_node) => {
                match rn.next.take() {
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

#[derive(Debug)]
struct LRUCache {
    capacity: usize,
    link: HashMap<i32, Rc<RefCell<DoublyLinkedListNode<(i32, i32)>>>>,
    list: DoublyLinkedList<(i32, i32)>
}

impl LRUCache {
    fn new(capacity: i32) -> Self {
        LRUCache {
            capacity: capacity as usize,
            link: HashMap::with_capacity(capacity as usize),
            list: DoublyLinkedList::new()
        }
    }

    fn get(&mut self, key: i32) -> i32 {
        match self.link.entry(key) {
            // key 를 찾았을 경우 해당 value를 return
            Entry::Occupied(mut o) => {
                let (k, v) = self.list.remove(o.get().clone());
                *o.get_mut() = self.list.push_front((k, v));
                v
            },
            _ => {
                // key 를 찾지 못한 경우 -1을 return
                -1
            }
        }
    }

    fn put(&mut self, key: i32, value: i32) {
        // 노드(페이지) 제거
        if self.link.contains_key(&key) {
            // key 가 이미 존재할 경우 해당 key 에 대한 노드 제거한다.
            self.list.remove(Rc::clone(self.link.get(&key).unwrap()));
        } else if self.capacity == self.list.len() {
            // 현재 할당된 크기가 최대 크기 한도와 같을 경우 연결 해제
            // DoublyLinkedList의 tail이 가리키는 노드를 제거한다. (가장 오랫동안 참조하지 않은 페이지)
            if let Some((k, _v)) = self.list.pop_back() {
                self.link.remove(&k);
            }
        }

        // 노드(페이지) 추가, push_front
        // 새로 참조하는 페이지 이므로 가장 앞에 위치 시킨다.
        self.link.insert(key, self.list.push_front((key, value)));
    }
}


pub fn run() {
    let mut lru_cache = LRUCache::new(2);
    println!("null");

    let (key, value) = (1, 1);
    lru_cache.put(key, value);
    println!("null");

    let (key, value) = (2, 2);
    lru_cache.put(key, value);
    println!("null");

    println!("{}", lru_cache.get(1));

    let (key, value) = (3, 3);
    lru_cache.put(key, value);
    println!("null");

    println!("{}", lru_cache.get(2));

    let (key, value) = (4, 4);
    lru_cache.put(key, value);
    println!("null");

    println!("{}", lru_cache.get(1));

    println!("{}", lru_cache.get(3));

    println!("{}", lru_cache.get(4));
}