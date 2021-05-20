class DoublyLinkedListNode<T>{
    public value : T;
    public prev : DoublyLinkedListNode<T> | null;
    public next : DoublyLinkedListNode<T> | null;
    constructor(value : T) {
        this.prev = null;
        this.value = value;
        this.next = null;
    }
}

//push_front, push_back, 
//pop_front, pop_back, 
//remove, 
//display_front, display_back
class DoublyLinkedList<T>{
    private head : DoublyLinkedListNode<T> | null;
    private tail : DoublyLinkedListNode<T> | null;
    public length : number;
    constructor(){
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    //list의 front에 data 삽입
    public push_front(value : T) : DoublyLinkedListNode<T> {
        const newHead = new DoublyLinkedListNode<T>(value);
        if(this.head === null){
            //tail이 새로운 노드를 가리킨다.
            this.tail = newHead;
        }else{
            //첫번째 노드의 prev와 newHead.next연결
            this.head.prev = newHead;
            newHead.next = this.head;
        }
        this.head = newHead;
        this.length++;
        return newHead;
    }
    
    //list의 back에 data 삽입
    public push_back(value : T) : DoublyLinkedListNode<T>{
        let newTail = new DoublyLinkedListNode<T>(value);
        if(this.tail === null){
            //head에 새로운 노드를 가리킨다
            this.head = newTail;
        }else{
            //마지막 노드의 next와 newtail.prev를 연결
            this.tail.next = newTail;
            newTail.prev = this.tail;
        }

        this.tail = newTail;
        this.length++;
        return newTail;
    }

    public pop_front() : DoublyLinkedListNode<T>{
        if(this.head === null) return null;

        if(this.head.next === null){
            this.tail = null;
        }else{
            this.head = this.head.next.prev
            this.head.next = null;
        }
        if(this.length > 0) this.length--;
        return this.head;
    }

    public pop_back(){
        if(this.tail === null) return null;
        
        if(this.tail.prev === null){
            this.head = null;
        }else{
            this.tail.next = null;
            this.tail = this.tail.prev.next;
        }
        console.log(this);
        if(this.length > 0) this.length--;
        return this.tail;
    }
    
    public remove(){
        if(this.length > 0) this.length--;

    }
}

export default function runDoublyLinkedList(){
    let dll = new DoublyLinkedList<number>();
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    console.log(dll);
    dll.pop_back();
    // dll.pop_back();
    // dll.pop_back();
    //console.log(dll);
}