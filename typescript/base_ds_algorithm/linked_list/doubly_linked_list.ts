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

    public push_front(value : T) : DoublyLinkedListNode<T> {
        const newHead = new DoublyLinkedListNode<T>(value);
        if(this.head === null){
            this.tail = newHead;
        }else{
            this.head.prev = newHead;
            newHead.next = this.head;
        }
        this.head = newHead;
        this.length++;
        return newHead;
    }
    
    public push_back(value : T) : DoublyLinkedListNode<T>{
        let newTail = new DoublyLinkedListNode<T>(value);
        if(this.tail === null){
            this.head = newTail;
        }else{
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
            this.head.next.prev = null;
            this.head = this.head.next
        }
        if(this.length > 0) this.length--;
        return this.head;
    }

    public pop_back(){
        if(this.tail === null) return null;
        
        if(this.tail.prev === null){
            this.head = null;
        }else{
            this.tail.prev.next = null;
            this.tail = this.tail.prev;
        }
        if(this.length > 0) this.length--;
        return this.tail;
    }
    
    public remove(node : DoublyLinkedListNode<T>) : T{
        if(node.prev === null && node.next === null){
            this.head = null;
            this.tail = null;
            this.length = 0;
            return node.value;
        }
        
        if(node.prev === null){
            this.head = node.next;
            this.head.prev = null;
        }else{
            if(node.prev.next === null){
                node.prev.next = null;
                this.tail = node.prev;
            }else{
                node.prev.next.next = node.prev.next;
                node.prev.next.prev = node.prev;
            }
        }
        if(this.length > 0) this.length--;
        return node.value;
    }
}

export default function runDoublyLinkedList(){
    let dll = new DoublyLinkedList<number>();
    let testNode = new DoublyLinkedListNode<number>(1);
    dll.push_front(1);
    console.log(dll);
    // dll.push_front(2);
    // dll.push_front(3);
    dll.remove(testNode);
    console.log(dll);
}