class DoublyLinkedListNode<T>{
    public value : T;
    public prev : DoublyLinkedListNode<T> | null;
    public next : DoublyLinkedListNode<T> | null;
    constructor(value : T) {
        this.value = value;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList<T>{
    private head : DoublyLinkedListNode<T> | null;
    private tail : DoublyLinkedListNode<T> | null;
    private length : number;
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
            this.head.next = this.head.prev;
            this.head.prev = newHead;
        }
        this.length++;
        //console.log(this);
        return newHead;
    }
    public push_back(value : T){
        let newTail = new DoublyLinkedListNode<T>(value);
        if(this.tail === null){

        }else{
            this.tail.prev = this.tail.next;
            this.tail.next = newTail;
        }
        //console.log(this);
        this.length++;
    }
    public pop_front(){
        this.length--;
    }
    public pop_back(){
        this.length--;
    }
    public remove(){
        this.length--;
    }
}



class LRUCache {
    private capacity : number;
    private link : Object;
    private list : DoublyLinkedList<Object>;
    constructor(capacity: number) {
        
    }

    get(key: number): number {
        return 1;
    }

    put(key: number, value: number): void {

    }
}


export function run(){
    // let test = new DoublyLinkedListNode<number>(1);
    // let test2 = new DoublyLinkedListNode<number>(2);
    // let test3 = new DoublyLinkedListNode<number>(3);
    // test.next = test2;
    // test.prev = test3;
    // console.log(test);

    let test = new DoublyLinkedList<number>();
    test.push_front(1);
    test.push_front(2);
    //test.push_back(2);
    console.log(test);
}