class Node {
  constructor(val, left, right) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

function tmp() {
  const node = new Node(
    5,
    new Node(2, new Node(1, new Node(0)), new Node(4, new Node(3))),
    new Node(7, new Node(6), new Node(8))
  );

  return node;
}

function recursion(node) {
  if (node.left) recursion(node.left);
  if (node.right) recursion(node.right);
}

recursion(tmp());
