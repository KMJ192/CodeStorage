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
  private head: Node<T> | null;
  private tail: Node<T> | null;
  private size: number;
  constructor() {
    this.head = null;
    this.tail = null;
    this.size = 0;
  }

  public push_front(value: T): void {
    const newHead = new Node<T>(value);
    if (this.head === null) {
      this.tail = newHead;
    } else {
      this.head.prev = newHead;
      newHead.next = this.head;
    }
    this.head = newHead;
    this.size++;
  }

  public push_back(value: T): void {
    const newTail = new Node<T>(value);
    if (this.tail === null) {
      this.head = newTail;
    } else {
      this.tail.next = newTail;
      newTail.prev = this.tail;
    }
    this.tail = newTail;
    this.size++;
  }

  public pop_front(): void {
    if (this.head === null) return;
    if (this.head.next === null) {
      this.tail = null;
    } else {
      this.head.next.prev = null;
      this.head = this.head.next;
    }
    this.size -= 1;
  }

  public pop_back(): void {
    if (this.tail === null) return;
    if (this.tail.prev === null) {
      this.head = null;
    } else {
      this.tail.prev.next = null;
      this.tail = this.tail.prev;
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
    this.iterator(this.head, "asc");
  }

  public display_descending() {
    this.iterator(this.tail, "desc");
  }
}

function doublyLinkedListRun() {
  const dll = new DoublyLinkedList();
  dll.push_front(1);
  dll.push_front(2);
  dll.push_back(3);

  dll.display_ascending();
  // dll.display_descending();
  dll.pop_back();
  dll.pop_front();
  dll.display_ascending();
}

export default doublyLinkedListRun;
