/*
  부모 노드와 자식 노드의 관계
  root node는 idx 1번부터 시작
  left index -> 부모노드 인덱스 * 2  
  right index -> 부모노드 인덱스 * 2 + 1
  부모노드의 인덱스 -> 자식노드 인덱스 / 2
  최대 힙 -> 부모 노드의 키 값이 자식노드보다 크거나 같은 완전 이진트리
  최소 힙 -> 부모 노드의 키 값이 자식 노드보다 작거나 같은 완전 이진 트리
*/

class Heap<T> {
  protected heap: { [key: number]: T };
  protected size: number;
  constructor() {
    this.heap = {};
    this.size = 1;
  }
}

class MaxHeap<T> extends Heap<T> {
  constructor() {
    super();
  }

  public push(value: T): void {
    this.heap[this.size] = value;

    let idx: number = this.size;
    while (this.heap[idx] > this.heap[Math.floor(idx / 2)]) {
      const pIdx = Math.floor(idx / 2);
      const currSpace: T = this.heap[idx];
      this.heap[idx] = this.heap[pIdx];
      this.heap[pIdx] = currSpace;
      idx = Math.floor(idx / 2);
    }
    this.size += 1;
  }

  public pop(): void {
    if (this.size === 1) return;
    this.size -= 1;
    this.heap[1] = this.heap[this.size];

    delete this.heap[this.size];

    let idx: number = 1;
    while (
      this.heap[idx * 2] > this.heap[idx] ||
      this.heap[idx * 2 + 1] > this.heap[idx]
    ) {
      const currSpace: T = this.heap[idx];
      const left: number = idx * 2;
      const right: number = idx * 2 + 1;

      if (this.heap[left] < this.heap[right]) {
        this.heap[idx] = this.heap[right];
        this.heap[right] = currSpace;
        idx = right;
      } else {
        this.heap[idx] = this.heap[left];
        this.heap[left] = currSpace;
        idx = left;
      }
    }
  }

  public top(): T {
    return this.heap[1];
  }

  public length(): number {
    return this.size - 1;
  }
}

class MinHeap<T> extends Heap<T> {
  constructor() {
    super();
  }

  public push(value: T): void {
    this.heap[this.size] = value;

    let idx: number = this.size;
    while (this.heap[idx] < this.heap[Math.floor(idx / 2)]) {
      const pIdx = Math.floor(idx / 2);
      const currSpace: T = this.heap[idx];
      this.heap[idx] = this.heap[pIdx];
      this.heap[pIdx] = currSpace;
      idx = Math.floor(idx / 2);
    }
    this.size += 1;
  }

  public pop(): void {
    if (this.size === 1) return;
    this.size -= 1;
    this.heap[1] = this.heap[this.size];

    delete this.heap[this.size];

    let idx: number = 1;
    while (
      this.heap[idx * 2] < this.heap[idx] ||
      this.heap[idx * 2 + 1] < this.heap[idx]
    ) {
      const currSpace: T = this.heap[idx];
      const left: number = idx * 2;
      const right: number = idx * 2 + 1;

      if (this.heap[left] > this.heap[right]) {
        this.heap[idx] = this.heap[right];
        this.heap[right] = currSpace;
        idx = right;
      } else {
        this.heap[idx] = this.heap[left];
        this.heap[left] = currSpace;
        idx = left;
      }
    }
  }

  public top(): T {
    return this.heap[1];
  }

  public length(): number {
    return this.size - 1;
  }
}

function priorityQueueRun() {
  const minHeap = new MinHeap();
  minHeap.push("test2");
  minHeap.push("test3");
  minHeap.push("test7");
  minHeap.push("test3");
  minHeap.push("test4");
  console.log(minHeap.top());
  minHeap.pop();
  console.log(minHeap.top());
  minHeap.pop();
  console.log(minHeap.top());
  minHeap.pop();
  console.log(minHeap.top());
  minHeap.pop();
  console.log(minHeap.top());
  minHeap.pop();

  console.log();

  const maxHeap = new MaxHeap();
  maxHeap.push("test2");
  maxHeap.push("test3");
  maxHeap.push("test7");
  maxHeap.push("test3");
  maxHeap.push("test4");
  console.log(maxHeap.top());
  maxHeap.pop();
  console.log(maxHeap.top());
  maxHeap.pop();
  console.log(maxHeap.top());
  maxHeap.pop();
  console.log(maxHeap.top());
  maxHeap.pop();
  console.log(maxHeap.top());
}

export default priorityQueueRun;
