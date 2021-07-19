#[derive(Debug)]
struct Node<T>{
    val: T,
    connect: Option<Box<Node<T>>>
}

#[derive(Debug)]
struct LinkedList<T>{
    next: Option<Box<Node<T>>>,
    len: usize
}

impl<T> LinkedList<T> where T: Copy{
    fn new() -> Self{
        LinkedList{
            next: None,
            len: 0
        }
    }
    fn push_front(&mut self, val: T){
        let new_node = Some(Box::new(Node{
            val,
            connect: self.next.take()
        }));
        self.next = new_node;
    }
    fn push_back(&mut self, val: T){
        self.len += 1;
        let mut new_node = match self.next{
            Some(ref mut a) => a,
            None => { // list 가 비어있을 때
                self.next = Some(Box::new(Node {
                    val,
                    connect: None
                }));
                return;
            }
        };
        while let Some(ref mut next) = new_node.connect {
            new_node = next;
        }
        new_node.connect = Some(Box::new(Node{
            val,
            connect: None
        }));
    }

    //Box smart pointer 추가학습 필요
    fn pop_back(&mut self){
        if self.len == 0 { return; }
        self.len -= 1;
    }

    fn pop_front(&mut self){
        if self.len == 0 { return; }
        self.len -= 1;
    }
}

pub fn run(){
    let mut list = LinkedList::new();
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.pop_back();
    //println!("{:#?}", list);
}