class Node{
    val: number;
    prev: Node | null;
    next: Node | null;
    constructor(value: number){
        this.val = value;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList{
    head: Node | null;
    tail: Node | null;
    length: number;
    constructor(){
        this.length = 0;
        this.head = null;
        this.tail = null;
    }
    push_back(val: number){
        const newTail = new Node(val);
        if(this.tail){
            this.tail.next = newTail;
            newTail.prev = this.tail;
        }else{
            this.head = newTail
        }
        this.tail = newTail
        this.length++;
    }
    len(): number {
        return this.length;
    }
}

function solution(n: number, k: number){
    let dll = new DoublyLinkedList();
    for(let i = 0; i < n; i++){
        dll.push_back(i);
    }
    //dll.head = dll.tail;
}

export function josephus(){
    let n = 7;
    let k = 3;

    solution(n, k);
}


