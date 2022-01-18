class Node<T> {
  value: T;
  link: Node<T> | null;
  constructor(value: T) {
    this.value = value;
    this.link = null;
  }
}

class Stack<T> {
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
      this.tail.link = curNode;
      this.size += 1;
      return;
    }
    this.tail = newNode;
    this.size += 1;
  }

  public pop() {
    if (!this.tail) return;
    const curNode = this.tail.link;
    this.tail = null;
    this.tail = curNode;
    this.size -= 1;
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
