#include<iostream>
#include<queue>
#include<string>
#include<vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    queue<TreeNode*> q;
    vector<string> v;
public:
    bool isSymmetric(TreeNode* root) {
        
        bfs(root);

        return false;
    }
    //Breadth First Search
    void bfs(TreeNode* root) {
        TreeNode* tmp;
        int startPnt = 0;

        //root노드 방문
        tmp = root;
        q.push(tmp);
        //v.push_back(tmp->val);

        //vector로 mirror 구현
        while (!q.empty()) {
            tmp = q.front();
            int front = q.front()->val;
            
            q.pop();
            if (tmp->left != nullptr) {
                q.push(tmp->left);
                v.push_back(to_string(tmp->left->val));
            }
            else {
                v.push_back("null");
            }
            if (tmp->right != nullptr){
                q.push(tmp->right);
                v.push_back(to_string(tmp->right->val));
            }
            else {
                v.push_back("null");
            }
        }

        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << "\n";
        }

        int cnt = 2, tmp1 = 1;
        int size = 0;
        while (size < v.size()) {
            if (tmp1 == 1) {
                if (size >= cnt * tmp1) {
                    tmp1 += size - 1;
                    cnt *= cnt;
                    cout << "\n";
                }
            }
            else {
                if (size >= cnt + tmp1) {
                    tmp1 += size - 1;
                    cnt *= cnt;
                    cout << "\n";
                }
            }
            cout << cnt << "\n";
            //cout << v[size] << "\n";
            size++;
        }

        delete tmp;
    }
};


int main() {
    //root노드
    TreeNode* tmp = new TreeNode(5);
    tmp->left = new TreeNode(6);
    tmp->right = new TreeNode(7);

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->left->left->left = tmp;
    root->left->left->right = tmp;
    root->left->right->left = tmp;
    root->left->right->right = tmp;

    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right= new TreeNode(3);

    Solution s;
    s.isSymmetric(root);

    delete root;

    return 0;
}