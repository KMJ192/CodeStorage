#include<iostream>
#include<queue>

using namespace std;

#define MAX_SIZE 100

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//��庰�� ��ġ�� ����ϱ�
//root node�� �������� �¿��� �� ���

//root ��� �������� ����/���� ������
// Binary Tree Structure
//        1
//    2       2
//  3  4   4  3

class Solution {
private:
    bool visited[MAX_SIZE];
public:
    bool isSymmetric(TreeNode* root) {

        //���� Ž��
        //1234243
        preOrder(root);
        cout << endl;
        //���� Ž��
        //2341243
        inOrder(root);
        cout << endl;
        //���� Ž��
        //2342431
        postOrder(root);
        cout << endl;

        return false;
    }

    //���� �켱 Ž��
    //���ȣ��� Ž��
    void preOrder(TreeNode* root) {
        cout << root->val << "\n";
        if (root->left != NULL) {
            preOrder(root->left); 
        }
        if (root->right != NULL) {
            preOrder(root->right);
        }
    }
    void inOrder(TreeNode* root) {
        if (root->left != NULL) {
            preOrder(root->left); 
        }
        cout << root->val << "\n";
        if (root->right != NULL) {
            preOrder(root->right);
        }
    }
    void postOrder(TreeNode* root) {
        if (root->left != NULL) {
            preOrder(root->left);
        }
        if (root->right != NULL) {
            preOrder(root->right);
        }
        cout << root->val << "\n";
    }
};


int main() {
    //root���
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right= new TreeNode(3);

    Solution s;
    s.isSymmetric(root);

    delete root;

    return 0;
}