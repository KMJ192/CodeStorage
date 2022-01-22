class Node<T> {
  public value: T;
  public prev: Node<T> | null;
  public next: Node<T> | null;
  constructor(value: T) {
    this.prev = null;
    this.value = value;
    this.next = null;
  }
}

class DoublyLinkedList<T> {
  private front: Node<T> | null; // List의 가장 앞의 노드
  private rear: Node<T> | null; // List의 가장 뒤의 노드
  private size: number;
  constructor() {
    this.front = null;
    this.rear = null;
    this.size = 0;
  }

  public push_front(value: T): void {
    const newNode = new Node<T>(value);
    if (this.front === null) {
      this.rear = newNode;
    } else {
      this.front.prev = newNode;
      newNode.next = this.front;
    }
    this.front = newNode;
    this.size++;
  }

  public push_back(value: T): void {
    const newNode = new Node<T>(value);
    if (this.rear === null) {
      this.front = newNode;
    } else {
      this.rear.next = newNode;
      newNode.prev = this.rear;
    }
    this.rear = newNode;
    this.size++;
  }

  public pop_front(): void {
    if (this.front === null) return;
    if (this.front.next === null) {
      this.front = null;
      this.rear = null;
    } else {
      this.front.next.prev = null;
      this.front = this.front.next;
    }
    this.size -= 1;
  }

  public pop_back(): void {
    if (this.rear === null) return;
    if (this.rear.prev === null) {
      this.front = null;
      this.rear = null;
    } else {
      this.rear.prev.next = null;
      this.rear = this.rear.prev;
    }
    this.size -= 1;
  }

  public length(): number {
    return this.size;
  }

  private iterator(node: Node<T>, type: string): void {
    console.log(node.value);
    if (type === "asc" && node.next) {
      this.iterator(node.next, type);
    }
    if (type === "desc" && node.prev) {
      this.iterator(node.prev, type);
    }
  }

  public display_ascending() {
    this.iterator(this.front, "asc");
  }

  public display_descending() {
    this.iterator(this.rear, "desc");
  }
}

function doublyLinkedListRun() {
  const dll = new DoublyLinkedList();
  dll.push_front(1);
  dll.push_front(2);
  dll.push_back(3);
  dll.pop_front();
  dll.pop_front();
  dll.pop_front();

  console.log(dll);
}

export default doublyLinkedListRun;
