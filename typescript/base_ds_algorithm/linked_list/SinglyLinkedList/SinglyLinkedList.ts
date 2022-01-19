class Node<T> {
  value: T;
  next: Node<T> | null;
  constructor(value: T) {
    this.value = value;
    this.next = null;
  }
}

class SinglyLinkedList<T> {
  private tail: Node<T> | null;
  private size: number;
  constructor() {
    this.tail = null;
    this.size = 0;
  }

  public top(): T | null {
    return this.tail ? this.tail.value : null;
  }

  public length(): number {
    return this.size;
  }

  public push(val: T) {
    const newNode = new Node(val);
    if (this.tail) {
      const curNode = this.tail;
      this.tail = newNode;
      this.tail.next = curNode;
      this.size += 1;
      return;
    }
    this.tail = newNode;
    this.size += 1;
  }

  public pop() {
    if (!this.tail) return;
    const curNode = this.tail.next;
    this.tail = null;
    this.tail = curNode;
    this.size -= 1;
  }
}

function singlyLinkedList() {
  const ssl = new SinglyLinkedList();
  ssl.push(1);
  ssl.push(2);
  console.log(ssl);
  ssl.pop();
  ssl.pop();
  console.log(ssl);
}

export default singlyLinkedList;
