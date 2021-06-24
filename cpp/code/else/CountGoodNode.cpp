//���� Ʈ�� ��Ʈ�� ������ Ʈ���� ��� X�� ��Ʈ���� X������ ��ο� X���� ū ���� ���� ��尡 ���� 
//��� �������� ���˴ϴ�.
//���� Ʈ���� ���� ��� ���� ��ȯ�մϴ�.

// input: 
//TreeNode* r = new TreeNode(3);
//TreeNode* rl = new TreeNode(1);
//TreeNode* rr = new TreeNode(4);
//TreeNode* rll = new TreeNode(3);
//TreeNode* rrl = new TreeNode(1);
//TreeNode* rrr = new TreeNode(5);
//rl->left = rll;
//rr->right = rrr;
//rr->left = rrl;
//r->left = rl;
//r->right = rr;

// output : 4
// constraint 
//  - ����� ���� 1 ~ 10^5
//  -10^4 ~ 10^4
// edge case: 
//    algorithm : dfs
//    ds : binary tree
//    time : O(n)
//    space : O(n)
//    code

#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode*left, TreeNode*right) : val(x), left(left), right(right) {}
};
 
class Solution {
    int count = 0;
public:
    int goodNodes(TreeNode* root) {
        int max = 0;
        max = root->val;
        dfs(root, root->val, root->val);

        return count;
    }

    void dfs(TreeNode* root, int rootVal, int max) {
        if (root == nullptr) return;
        
        if (max <= root->val) {
            max = root->val;
            if (root->val >= rootVal)
                count++;
        }

        dfs(root->left, rootVal, max);
        dfs(root->right, rootVal, max);
    }
};

int main() {
    TreeNode* r = new TreeNode(2);

    TreeNode* rl = new TreeNode(1);
    TreeNode* rr = new TreeNode(4);

    TreeNode* rll = new TreeNode(3);
    TreeNode* rrl = new TreeNode(1);
    TreeNode* rrr = new TreeNode(5);

    rl->left = rll;
    rr->right = rrr;
    rr->left = rrl;

    r->left = rl;
    r->right = rr;

    Solution s;
    cout << s.goodNodes(r) << endl;

    return 0;
}