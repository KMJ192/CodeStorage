#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    int cnt = 0;
public:
    int goodNodes(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return 1;
        recursion(root, root->val);

        return cnt;
    }

    // back tracking
    void recursion(TreeNode* root, int m) {
        if (root->left != nullptr) recursion(root->left, max(root->val, m));
        if (root->right != nullptr) recursion(root->right, max(root->val, m));

        if (root->val >= m) cnt++;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    TreeNode* l = new TreeNode(1, new TreeNode(3), nullptr);
    TreeNode* r = new TreeNode(4, new TreeNode(1), new TreeNode(5));
    root->left = l;
    root->right = r;
    Solution s;
    cout << s.goodNodes(root);

    delete root;

    return 0;
}