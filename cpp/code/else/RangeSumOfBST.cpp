#include<iostream>

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
    int total = 0;
public:
    //7, 15
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return 0;

        cout << root->val << endl;

        if (root->val >= low && root->val <= high) {
            total += root->val;
            rangeSumBST(root->left, low, high);
            rangeSumBST(root->right, low, high);
        } 
        else if (root->val < low) {
            rangeSumBST(root->right, low, high);
        }
        else if (root->val > high) {
            rangeSumBST(root->left, low, high);
        }

        return total;
    }
};

int main() {
    TreeNode* r = new TreeNode(10);
    
    TreeNode* c1 = new TreeNode(3);
    TreeNode* c2 = new TreeNode(7);

    TreeNode* c = new TreeNode(5);

    c->left = c1;
    c->right = c2;

    TreeNode* d1 = new TreeNode(18);
    TreeNode* d = new TreeNode(15);

    d->right = d1;

    r->left = c;
    r->right = d;

    Solution s;
    int tmp = s.rangeSumBST(r, 7, 15);
    cout << tmp << endl;

	return 0;
}