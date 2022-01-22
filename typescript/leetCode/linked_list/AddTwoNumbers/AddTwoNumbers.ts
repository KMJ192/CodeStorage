class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

class List {
  front: ListNode | null;
  rear: ListNode | null;
  constructor() {
    this.front = null;
    this.rear = null;
  }

  push(value: number) {
    const newNode = new ListNode(value);
    if (this.front === null) {
      this.front = newNode;
      this.rear = newNode;
      return;
    }
    this.rear.next = newNode;
    this.rear = newNode;
  }
}

class Solution {
  private l1: ListNode | null;
  private l2: ListNode | null;
  private curNode: ListNode | null;

  constructor(l1: ListNode | null, l2: ListNode | null) {
    this.l1 = l1;
    this.l2 = l2;
    this.curNode = null;
  }

  private recursive(
    l1: ListNode | null,
    l2: ListNode | null,
    q: List,
    mod: number
  ) {
    if (!l1 && !l2) {
      if (mod) q.push(mod);
      return;
    }

    let l1Val = 0,
      l2Val = 0;
    if (l1) l1Val = l1.val;
    if (l2) l2Val = l2.val;
    let value: number = l1Val + l2Val + mod;
    mod = 0;
    if (value >= 10) {
      mod = Number(String(value).substring(0, 1));
      value = Number(String(value).substring(1));
    }
    q.push(value);

    if (l1 && l2) {
      this.recursive(l1.next, l2.next, q, mod);
      return;
    }
    if (!l1 && l2) {
      this.recursive(null, l2.next, q, mod);
      return;
    }
    if (l1 && !l2) {
      this.recursive(l1.next, null, q, mod);
      return;
    }
  }

  run(): ListNode | null {
    const q = new List();
    this.recursive(this.l1, this.l2, q, 0);
    return q.front;
  }
}

function addTwoNumbers(
  l1: ListNode | null,
  l2: ListNode | null
): ListNode | null {
  return new Solution(l1, l2).run();
}

function run() {
  const l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  const l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

  console.log(addTwoNumbers(l1, l2));
}

export default run;
