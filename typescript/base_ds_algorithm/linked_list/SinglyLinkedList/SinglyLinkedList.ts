class Node<T> {
  value: T;
  next: Node<T> | null;
  constructor(value: T) {
    this.value = value;
    this.next = null;
  }
}

class SinglyLinkedList<T> {
  private front: Node<T> | null;
  private rear: Node<T> | null;
  private size: number;
  constructor() {
    this.front = null;
    this.rear = null;
    this.size = 0;
  }

  public top(): T | null {
    return this.front ? this.front.value : null;
  }

  public bottom(): T | null {
    return this.rear ? this.rear.value : null;
  }

  public length(): number {
    return this.size;
  }

  public push(val: T) {
    const newNode = new Node(val);
    if (this.front === null) {
      this.front = newNode;
      this.rear = newNode;
      this.size += 1;
      return;
    }
    this.rear.next = newNode;
    this.rear = newNode;

    this.size += 1;
  }

  public pop() {
    if (!this.front) return;
    const curNode = this.front.next;
    this.front.next = null;
    this.front = curNode;
    if (this.front === null) {
      this.rear = null;
    }
    this.size -= 1;
  }

  private iterator(node: Node<T>) {
    if (node) {
      console.log(node.value);
      if (node.next) this.iterator(node.next);
    }
  }

  public display() {
    this.iterator(this.front);
  }
}

function singlyLinkedList() {
  const ssl = new SinglyLinkedList();
  ssl.push(1);
  ssl.display();
  ssl.push(2);
  ssl.push(3);
  ssl.display();
  ssl.pop();
  ssl.display();
}

export default singlyLinkedList;
