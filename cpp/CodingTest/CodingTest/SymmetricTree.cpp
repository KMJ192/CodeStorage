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
    vector<TreeNode*> compare;
    vector<int> v;
public:
    Solution() {}
    ~Solution() {}

    int commonLevel(TreeNode* node) {
        int cnt = 0;
        if (node->left) {
            compare.push_back(node->left);
            cnt++;
        }
        if (node->right) {
            compare.push_back(node->left);
            cnt++;
        }
    }

    bool isSymmetric(TreeNode* root) {
        TreeNode* tmp;
        tmp = root;
        q.push(tmp);
        compare.push_back(tmp);
        while (!q.empty()) {            
            int lCnt = 0;
            tmp = q.front();
            q.pop();
            if (tmp->left != nullptr) {
                lCnt++;
                q.push(tmp->left);
                compare.push_back(tmp->left);
            }
            if (tmp->right != nullptr) {
                lCnt++;
                q.push(tmp->right);
                compare.push_back(tmp->right);
            }
            v.push_back(lCnt);
        }
        int next = 0;
        int init = 0;
        int cnt = 0;
        bool toggle = false;
        for (int i = 0; i < compare.size(); i++) {
            if (toggle == false) {
                init = next = v[i] + i;
                toggle = true;
                cnt = 0;
            }
            else {
                cnt += v[i];
            }
            cout << compare[i]->val << " ";
            cout << v[i] << endl;
            if (next == i) {
                cout << "test" << endl;
                toggle = false;
                cout << "간선의 수 : " << cnt << endl;
            }
        }
        

        delete tmp;
        return true;
    }
};


int main() {
    //root노드
    TreeNode* root = new TreeNode(2);

    root->left = new TreeNode(3);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);
    
    root->left->left->right = new TreeNode(5);
    root->right->right->left = new TreeNode(5);

    root->left->left->right->right = new TreeNode(6);
    root->right->right->left->left = new TreeNode(6);

    root->left->left->right->right->left = new TreeNode(7);
    root->left->left->right->right->right = new TreeNode(8);
    root->right->right->left->left->left = new TreeNode(8);
    root->right->right->left->left->right = new TreeNode(7);


    root->left->left->right->right->left->left = new TreeNode(9);
    root->left->left->right->right->left->right = new TreeNode(0);
    root->left->left->right->right->right->left = new TreeNode(0);
    root->left->left->right->right->right->right = new TreeNode(1);
    root->right->right->left->left->left->left = new TreeNode(1);
    root->right->right->left->left->left->right = new TreeNode(0);
    root->right->right->left->left->right->left = new TreeNode(0);
    root->right->right->left->left->right->right = new TreeNode(9);


    Solution s;
    s.isSymmetric(root);

    delete root;

    return 0;
}

//Input: 
//Output: return value
//Constraints :
// 1) num of nodes,
// 2) node value = pos or neg
//Edge Case :
// 1) tree == = null, return root;
//
//brute force : naive
//  DFS or BFS or iteratively or recursive
//  time, space
//optimal solution
//  algorithmand Data structure
//  time, space
//
//code :
//  function