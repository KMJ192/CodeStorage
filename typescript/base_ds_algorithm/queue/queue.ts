class Node<T> {
  value: T;
  link: Node<T> | null;
  constructor(value: T) {
    this.value = value;
    this.link = null;
  }
}

class Queue<T> {
  private head: Node<T> | null;
  private size: number;

  constructor() {
    this.head = null;
    this.size = 0;
  }

  public top(): T | null {
    return this.head ? this.head.value : null;
  }

  public length(): number {
    return this.size;
  }

  public push(val: T) {
    const newNode = new Node(val);
    if (this.head) {
      const curNode = this.head.link;
      newNode.link = curNode;
      this.head.link = newNode;
      return;
    }
    this.head = newNode;
    this.size += 1;
  }

  public pop() {
    if (!this.head) return;
    const curNode = this.head.link;
    this.head.link = null;
    this.head = curNode;
    this.size -= 1;
  }
}

function queueTest() {
  const q = new Queue<number>();
  q.push(1);
  console.log(q.top()); // 1
  q.push(2);
  console.log(q.top()); // 1
  q.pop();
  console.log(q.top()); // 2
  q.push(3);
  console.log(q.top()); // 2
  q.pop();
  console.log(q.top()); // 3

  const sq = new Queue<string>();
  sq.push("test");
  console.log(sq.top());
  sq.push("test2");
  console.log(sq.top());
  sq.pop();
  console.log(sq.top());
  sq.pop();
  console.log(sq.top());
}

export default queueTest;
