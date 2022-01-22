class Node<T> {
  value: T;
  link: Node<T> | null;
  constructor(value: T) {
    this.value = value;
    this.link = null;
  }
}

class Stack<T> {
  private rear: Node<T> | null;
  private size: number;

  constructor() {
    this.rear = null;
    this.size = 0;
  }

  public top(): T | null {
    return this.rear ? this.rear.value : null;
  }

  public length(): number {
    return this.size;
  }

  public push(val: T) {
    const newNode = new Node(val);
    if (this.rear) {
      const curNode = this.rear;
      this.rear = newNode;
      this.rear.link = curNode;
      this.size += 1;
      return;
    }
    this.rear = newNode;
    this.size += 1;
  }

  public pop() {
    if (!this.rear) return;
    const curNode = this.rear.link;
    this.rear = null;
    this.rear = curNode;
    this.size -= 1;
  }

  public isEmpty(): boolean {
    return this.rear === null;
  }
}

function stackRun() {
  const s = new Stack();
  s.push(1);
  console.log(s.top());
  s.push(2);
  console.log(s.top());
  s.pop();
  console.log(s.top());
  s.pop();
  console.log(s.top());

  const t = new Stack();
  t.push("test1");
  console.log(t.top());
  t.push("test2");
  console.log(t.top());
  t.pop();
  console.log(t.top());
  t.pop();
  console.log(t.top());
}
export default stackRun;
