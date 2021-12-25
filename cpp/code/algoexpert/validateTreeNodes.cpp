#include <iostream>
#include <vector>

using namespace std;

// time O(2nm)
// space O(nm)

struct Node {
  int val;
  Node* left;
  Node* right;
  Node() : val(0), left(nullptr), right(nullptr) {}
  Node(int x) : val(x), left(nullptr), right(nullptr) {}
  Node(int x, Node* left, Node* right) : val(x), left(left), right(right) {}
};

class Solution {
  int one;
  int two;
  int three;
  bool valid;
  bool next = false;
  vector<vector<int>> line; 

  bool one2, two2, three2;
public:
  Solution() {
    valid = false;
  }
  bool vaildateTreeNodes(Node* tree, int nodeOne, int nodeTwo, int nodeThree) {
    one = nodeOne, two = nodeTwo, three = nodeThree;
    vector<int> tmp;

    recursion(tree, tmp);

    for (int i = 0; i < line.size(); i++) {
      for (int j = 0; j < line[i].size(); j++) {
        if (line[i][j] == two) {
          // 중간 값을 찾음
          for (int n = j + 1; n < line[i].size(); n++) {
            // 다음 값을 찾음
            if (line[i][n] == three || line[i][n] == one){
              // 이전 값을 찾음
              for (int m = j - 1; m >= 0; m--) {
                if (line[i][m] == three || line[i][m] == one){
                  // 모든 조건에 부합함
                  return true;
                }
              }
            }
          }
        }
      }
    }

    return valid;
  }

  void recursion(Node* tree, vector<int> tmp) {
    tmp.push_back(tree->val);
    if (tree->val == two) {
      next = true;
    }
    if (tree->left != nullptr) recursion(tree->left, tmp);
    if (tree->right != nullptr) recursion(tree->right, tmp);
    if (tree->left == nullptr && tree->right == nullptr) {
      if (tmp.size() > 0) line.push_back(tmp);
      tmp.clear();
    }
  }
};

/*
5210
5243
576
578
*/

int main() {
  Solution s;

  Node* tree = new Node(5, 
    new Node(2,
      new Node(1, new Node(0), nullptr),
      new Node(4, new Node(3), nullptr)
    ), 
    new Node(7,
      new Node(6),
      new Node(8)
    )
  );

  bool find = s.vaildateTreeNodes(tree, 5, 2, 3);
  if (find == true) cout << "찾았다" << endl;
  else cout << "없다" << endl;

  return 0;
}