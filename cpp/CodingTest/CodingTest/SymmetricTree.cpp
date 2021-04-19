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

//노드별로 위치값 계산하기
//root node를 기준으로 좌우의 값 계산

//root 노드 기준으로 좌측/우측 나누기
// Binary Tree Structure
//        1
//    2       2
//  3  4   4  3

class Solution {
private:
    bool visited[MAX_SIZE];
public:
    bool isSymmetric(TreeNode* root) {

        //전위 탐색
        //1234243
        preOrder(root);
        cout << endl;
        //중위 탐색
        //2341243
        inOrder(root);
        cout << endl;
        //후위 탐색
        //2342431
        postOrder(root);
        cout << endl;

        return false;
    }

    //깊이 우선 탐색
    //재귀호출로 탐색
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
    //root노드
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