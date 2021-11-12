#include <iostream>
#include <cmath>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  int m = INT_MAX;
public:
    int minDepth(TreeNode* root) {
      if(root == nullptr) return 0;
      if(root->left == nullptr && root->right == nullptr) return 1;
      minDepth(root, 1);

      return m;
    }
    
    void minDepth(TreeNode* node, int count) {
      if(node->left != nullptr) minDepth(node->left, count+1);
      if(node->right != nullptr) minDepth(node->right, count+1);

      if(node->left == nullptr && node->right == nullptr && count != 1) m = min(m, count);

    }
};

int main(){
  TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  // TreeNode* root = new TreeNode(2, nullptr, new TreeNode(3, nullptr, new TreeNode(4, nullptr, new TreeNode(5, nullptr, new TreeNode(6)))));
  Solution s;
  cout << s.minDepth(root) << "\n";
  return 0;
}