/*
 Tree 만들어보기
*/
#include <iostream>
#include <queue>

using namespace std;

struct Node {
  string value;
  Node* left;
  Node* right;
  Node(): value(0), left(nullptr), right(nullptr) {}
  Node(string x): value(x), left(nullptr), right(nullptr) {}
  Node(string x, Node* l, Node* r): value(x), left(l), right(r) {}
};

// bfs - 너비 우선 탐색, Tree 자료구조에서 Level by level로 탐색하는 알고리즘
void bfs(Node* root) {
  // 선입선출 FIFO
  queue<Node*> q;
  q.push(root);
  while(!q.empty()) {
    Node* top = q.front();
    q.pop();
    cout << top->value << " ";
    if (top->left != nullptr) q.push(top->left);
    if (top->right != nullptr) q.push(top->right);
  }
}
 
/*
  dfs - 깊이우선탐색 
  for, while 구문 쓸필요가 없음
  재귀호출
*/
void recursion(Node* root) {
  cout << root->value << " ";
  if (root->left != nullptr) recursion(root->left); 
  if (root->right != nullptr) recursion(root->right);
}

/*
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
"""
*/

int main() {
  Node* tree = new Node(
    "A",
    new Node("B", 
      new Node("D",
        new Node("H"),
        new Node("I")
      ),
      new Node("E",
        new Node("J"),
        nullptr
      )
    ),
    new Node("C",
      new Node("F"),
      new Node("G")
    )
  );


  // 함수 실행
  cout << "BFS : ";
  bfs(tree);
  cout << "\n";
  cout << "DFS : ";
  recursion(tree);

  delete tree;

  return 0;
}
