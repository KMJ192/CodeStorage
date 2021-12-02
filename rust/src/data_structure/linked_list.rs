use std::fmt::Debug;

#[derive(Debug)]
struct Node<T> {
    val: Option<T>,
    next: Option<Box<Node<T>>>
}

#[derive(Debug)]
struct LinkedList<T> {
    head: Option<Box<Node<T>>>,
    len: usize
}

impl<T> LinkedList<T> where T: Debug {
    fn new() -> Self {
        LinkedList {
            head: None,
            len: 0
        }
    }

    fn push_front(&mut self, val: T) {
        let new_node = Node {
            val: Some(val),
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
                    val: Some(val),
                    next: self.head.take(),
                };
                self.head = Some(Box::new(new_node));
                self.len += 1;
                return;
            }
        };

        while let Some(ref mut next) = prev_node.next {
            prev_node = next;
        }

        let node = Node {
            val: Some(val),
            next: None
        };

        prev_node.next = Some(Box::new(node));
        self.len += 1;
    }

    fn pop_front(&mut self) {
        // self.head 유무 검사
        match self.head.take() {
            Some(head) => {
                // self.head.next 유무 검사
                match head.next {
                    Some(next) => {
                        self.head = None;
                        self.head = Some(next);
                    }
                    _ => {
                        self.head = None;
                    }
                }
            },
            _ => {
                return;
            }
        }
        if self.len > 0 { self.len -= 1;}
    }

    fn pop_back(&mut self) {
        let mut dummy_head = Box::new(Node {
            val: None,
            next: self.head.take(),
        });
        let mut idx = 0;
        let mut cur = &mut dummy_head;
        while idx < self.len - 1 {
            if let Some(ref mut next) = cur.next {
                cur = next;
            }
            idx += 1;
        }
        cur.next = cur.next.take().and_then(|a| a.next);
        self.head = dummy_head.next;

        // match self.head {
        //     Some(ref mut node) => {
        //         let mut cur_node = node;
        //         while let Some(ref mut next)= cur_node.next {
        //             match next.next {
        //                 None => {
        //                     println!("{:?}", next);
        //                     break;
        //                 },
        //                 _ => {
        //
        //
        //                     cur_node = next;
        //                 }
        //             }
        //         }
        //     },
        //     _ => {
        //         return;
        //     }
        // };

        if self.len > 0 { self.len -= 1; }
    }

    fn display(&mut self) {
        match self.head.take() {
            Some(ref mut node) => {
                println!("{:?}", node.val);
                let mut cur_node = node;
                while let Some(ref mut next) = cur_node.next {
                    println!("{:?}", next.val);
                    cur_node = next;
                }
            },
            _ => {
                return;
            }
        };
    }

    fn test(&mut self) {
        let tmp = self.head.take();
        let tmp = tmp.and_then(|a|  {
            println!("{:?}", a);
            a.next
        });
        let tmp = tmp.and_then(|a|  {
            println!("{:?}", a);
            a.next
        });
        let tmp = tmp.and_then(|a|  {
            println!("{:?}", a);
            a.next
        });
        // println!("{:?}", tmp);
    }
}

pub fn run() {
    let mut ll: LinkedList<i32> = LinkedList::new();
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.pop_back();
    // ll.test();
    // ll.display();
    println!("==================================");
    println!("{:?}", ll);
    println!("==================================");

    // let test_box = Box::new(String::from("test"));
    // let mut tmp = *test_box;
    // println!("{}", tmp);

    // let tmp = Some(Box::new(Node{
    //     val: 1,
    //     next: None
    // }));
    //
    // let next = match tmp {
    //     Some(a) => {
    //         println!("{}", a.val);
    //         Some(a)
    //     },
    //     None => None,
    // };
    //
    // println!("{:?}", next);
}