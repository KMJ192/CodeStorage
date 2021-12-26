class Node {
  value: number;
  next: Node | null;
  prev: Node | null;
  constructor(value: number, prev: Node | null, next: Node | null) {
    this.value = value;
    this.prev = prev || null;
    this.next = next || null;
  }
}

class DoublyLinkedList {
  table: { [key: string]: Node };
  head: Node | null;
  tail: Node | null;
  length: number;
  constructor() {
    this.table = {};
    this.head = null;
    this.tail = null;
    this.length = 0;
  }

  public insert(param: InsertType) {
    const { object, pushPosition: pos, value } = param;
    const { table, head, tail } = this;
    const key = String(value);
    const obj = String(object);

    const newNode: Node | null = new Node(value, null, null);

    // key | value table에 node할당
    this.table = {
      ...table,
      [key]: newNode,
    };

    // 최초입력, parameter로 position이 "first"가 아니라도, this.length === 0 일때 최초할당
    if (pos === "first" || this.length === 0) {
      if (this.length > 0) return;
      this.head = newNode;
      this.tail = newNode;
      this.length++;
      return;
    }

    // 대상 node(table[obj])의 prev에 새로운 노드 할당
    if (pos === "front" && table[obj]) {
      if (head === table[obj]) {
        // 대상 노드가 head일 경우 head를 새로운 노드로 교체
        this.head = newNode;
      } else if (table[obj].prev) {
        // 새로운 노드의 prev와 대상 노드prev의 next가 서로 가리키도록 설정
        newNode.prev = table[obj].prev;
        (table[obj].prev as Node).next = newNode;
      }
      // 대상 노드의 prev와 새로운 노드의 next가 서로 가리키도록 설정
      table[obj].prev = newNode;
      newNode.next = table[obj];
    }

    // 대상 node(table[obj])의 next에 새로운 노드 할당
    if (pos === "back" && table[obj]) {
      if (tail === table[obj]) {
        // 대상 노드가 tail일 경우 tail을 새로운 노드로 교체
        this.tail = newNode;
      } else if (table[obj].next) {
        // 새로운 노드의 next와 대상 노드next의 prev가 서로 가리키도록 설정
        newNode.next = table[obj].next;
        (table[obj].next as Node).prev = newNode;
      }
      // 대상 노드의 next와 새로운 노드의 prev가 서로 가리키도록 설정
      table[obj].next = newNode;
      newNode.prev = table[obj];
    }

    // DoublyLinkedList 길이를 증가시켜두기
    this.length++;
  }

  public display() {
    this.head && this.curDisplay(this.head);
  }
  private curDisplay(node: Node) {
    console.log(node.value);
    if (node.next) this.curDisplay(node.next);
  }
}

interface InsertType {
  object?: number;
  pushPosition: "first" | "front" | "back";
  value: number;
}

class TreeNode {
  value: number;
  right: TreeNode | null;
  left: TreeNode | null;
  constructor(value: number, l: TreeNode | null, r: TreeNode | null) {
    this.value = value;
    this.left = l;
    this.right = r;
  }
}

// FlattenBinaryTree문제 풀이
function solution(tree: TreeNode) {
  let ll = new DoublyLinkedList();
  const { value } = tree;
  const param: InsertType = {
    pushPosition: "first",
    value,
  };

  // DoublyLinkedList에 최초 값 할당
  ll.insert(param);
  recursion(tree, ll);

  // 결과 출력
  ll.display();
}

function recursion(node: TreeNode, ll: DoublyLinkedList) {
  if (node.left) {
    const { value, left } = node;
    const param: InsertType = {
      object: value,
      pushPosition: "front",
      value: left.value,
    };
    ll.insert(param);
    recursion(left, ll);
  }

  if (node.right) {
    const { value, right } = node;
    const param: InsertType = {
      object: value,
      pushPosition: "back",
      value: right.value,
    };
    ll.insert(param);
    recursion(right, ll);
  }
}

export function flattenBinaryTree() {
  const tree = new TreeNode(
    1,
    new TreeNode(
      2,
      new TreeNode(4, null, null),
      new TreeNode(5, new TreeNode(7, null, null), new TreeNode(8, null, null))
    ),
    new TreeNode(3, new TreeNode(6, null, null), null)
  );
  solution(tree);
}
