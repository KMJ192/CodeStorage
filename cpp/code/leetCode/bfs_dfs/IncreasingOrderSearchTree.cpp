#include <iostream>
#include <algorithm>
#include <queue>

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
private:
    priority_queue<int> q;
    TreeNode* answer = new TreeNode();
public:
    TreeNode* increasingBST(TreeNode* root) {
        recursionSearch(root);
        answer->val = q.top();
        q.pop();
        while (!q.empty()) {
            TreeNode* parent = new TreeNode(q.top());
            answer = buildTree(parent, answer);
            q.pop();
        }
        return answer;
    }

    void recursionSearch(TreeNode* node) {
        // v.push_back(node->val);
        q.push(node->val);
        if (node->left != nullptr) recursionSearch(node->left);
        if (node->right != nullptr) recursionSearch(node->right);
    }

    TreeNode* buildTree(TreeNode* parent, TreeNode* child) {
        parent->right = child;
        return parent;
    }

    void recursion(TreeNode* node) {
        cout << node->val << endl;
        if (node->right != nullptr) recursion(node->right);
    }
};

int main() {

    TreeNode* root = new TreeNode(5);
    TreeNode* l = new TreeNode(3);
    TreeNode* ll = new TreeNode(2);
    TreeNode* lll = new TreeNode(1);
    TreeNode* lr = new TreeNode(4);

    TreeNode* r = new TreeNode(6);
    TreeNode* rl = new TreeNode(8);
    TreeNode* rll = new TreeNode(7);
    TreeNode* rlr = new TreeNode(9);

    rl->left = rll;
    rl->right = rlr;

    r->right = rl;

    ll->left = lll;
    l->left = ll;
    l->right = lr;
    root->left = l;
    root->right = r;

    Solution s;
    s.increasingBST(root);

    return 0;
}