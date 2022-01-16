/*
  11:51 ~ 12:21
  Find the path with the maximum sum in a given binary tree. 
  Write a function that returns the maximum sum.

  A path can be defined as a sequence of nodes between any two nodes and doesn’t necessarily pass through the root. 
  The path must contain at least one node.

  parents 노드
  자식노드부터 끝까지 더한값의 합이 가장 큰 수를 return

  - root노드 가 포함될 필요는 없다.
  p
  1. brute force
    recursion call -> 왼쪽 부터 탐색
    특정 노드가 root 노드라고 생각하고 전체를 순회하는 방법 -> back tracking
    1
  ↙ ↘
  2     3
 ↙↘  ↙ ↘
1   3  5     6
      ↙↘  ↙    
      7  8  9
// root
1 -> max: 31

// 왼쪽
1 -> max: 1, prev: 1
3 -> max: 3, prev: 3
2 -> max: 6, prev: 5

// 오른쪽
7 -> max: 7, prev: 7
8 -> max: 8, prev: 8
5 -> max: 20, prev: 13
9 -> max: 20, prev: 9
6 -> max: 20, prev: 15
3 -> max: 31, prev: 18

  2. optimal

*/
class Node {
  value: number;
  left?: Node;
  right?: Node;
  constructor(value: number, l?: Node, r?: Node) {
    this.left = l;
    this.right = r;
    this.value = value;
  }
}

class Solution {
  private max: number;
  private prev: number;
  constructor() {
    this.max = 0;
    this.prev = 0;
  }

  private backtracking(root?: Node): void {
    if (root.left) {
      this.backtracking(root.left);
    }
    if (root.right) {
      this.backtracking(root.right);
    }
  }

  public run(root: Node): number {
    this.backtracking(root);
    return this.max;
  }
}

function run() {
  const root = new Node(
    1,
    new Node(2, new Node(1), new Node(3)),
    new Node(3, new Node(5, new Node(7), new Node(8)), new Node(6, new Node(9)))
  );
  const solution = new Solution();
  console.log(solution.run(root));
}

export default run;
