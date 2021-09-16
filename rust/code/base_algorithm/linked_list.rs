use std::borrow::{BorrowMut, Borrow};

#[derive(Debug)]
struct Node<T> {
    val: T,
    next: Option<Box<Node<T>>>
}

#[derive(Debug)]
struct LinkedList<T> {
    head: Option<Box<Node<T>>>,
    len: usize
}

impl<T> LinkedList<T> {
    fn new() -> Self {
        LinkedList {
            head: None,
            len: 0
        }
    }

    fn push_front(&mut self, val: T) {
        let new_node = Node {
            val,
            next: self.head.take()
        };
        self.head = Some(Box::new(new_node));
        self.len += 1;
    }

    fn push_back(&mut self, val: T) {
        let mut prev_node = match self.head {
            Some(ref mut a) => a,
            None => {
                // head가 없으니 새로운 node를 만든다.
                let new_node = Node {
                    val,
                    next: self.head.take()
                };
                self.head = Some(Box::new(new_node));
                return;
            }
        };

        while let Some(ref mut next) = prev_node.next {
            prev_node = next;
        }

        let node = Node {
            val,
            next: None
        };

        prev_node.next = Some(Box::new(node));
        self.len += 1;
    }

    fn pop_front(&mut self) {
        match &self.head.take() {
            Some(head_node) => {
                // self.head = head_node.next.take().and_then(|a| a.next);
            },
            _ => {
                self.head = None
            }
        }
        self.len -= 1;
    }

    fn pop_back(&mut self) {
        if self.len == 0 { return; }
        self.len -= 1;
    }
}

pub fn run() {
    // let mut ll = LinkedList::new();
    // ll.push_front(1);
    // ll.push_front(2);
    // ll.push_back(3);
    // println!("{:#?}", ll.head.unwrap());

    // let test_box = Box::new(String::from("test"));
    // let mut tmp = *test_box;
    // println!("{}", tmp);

    let tmp = Some(Box::new(Node{
        val: 1,
        next: None
    }));

    let next = match tmp {
        Some(a) => {
            println!("{}", a.val);
            Some(a)
        },
        None => None,
    };

    println!("{:?}", next);
}