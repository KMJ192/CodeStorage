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
    vector<pair<TreeNode*, int>> compare;
    vector<int> v;
public:
    Solution() {}
    ~Solution() {}

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        else if (root->left == nullptr || root->right == nullptr) return false;

        TreeNode* tmp;
        tmp = root;

        int line = 0, count = 0;
        q.push(tmp); 
        compare.push_back(pair<TreeNode*, int>(tmp, 2));
        while (!q.empty()) {
            tmp = q.front();
            //cout << tmp->val << endl;
            q.pop();

            if (tmp->left != nullptr) {
                count = 0;
                q.push(tmp->left);
                if (tmp->left->left != nullptr) {
                    count++;
                }
                if (tmp->left->right != nullptr) {
                    count++;
                }
                compare.push_back(pair<TreeNode*, int>(tmp->left, count));
            }
            else {
                compare.push_back(pair<TreeNode*, int>(new TreeNode(-1), 0));
            }

            if (tmp->right != nullptr) {
                count = 0;
                q.push(tmp->right);
                if (tmp->right->left != nullptr) {
                    count++;
                }
                if (tmp->right->right != nullptr) {
                    count++;
                }
                compare.push_back(pair<TreeNode*, int>(tmp->right, count));
            }
            else {
                compare.push_back(pair<TreeNode*, int>(new TreeNode(-1), 0));
            }
        }

        line = 0;
        count = 0;
        cout << compare[0].first->val << ", " << compare[0].second << endl;
        cout << endl;
        int test = compare[0].second;
        int nodeCnt = 0, nodeCntTmp = 0;
        int brunch = 0;
        for (int i = 1; i < compare.size(); i++) {
            if (nodeCnt == nodeCntTmp + nodeCntTmp) {
                cout << endl;
                count = 0;
                brunch = 0;
            }
            if (compare[i].second != -1) {
                
            }
            cout << compare[i].first->val << ", " << compare[i].second << endl;

            count++;
        }

        int test2 = 0, test3 = 0;
        for (int i = 1; i < compare.size(); i++) {
            if (count == line) {
                if (i == 1) {
                    count = 0;
                    line = test;
                    test = 0;
                    test += compare[i].second;
                    cout << endl;
                }
                if (test2 + test2 == test3) {
                    test3 = 0;
                    count = 0;
                    line = test;
                    test2 = line;
                    test = 0;
                    test += compare[i].second;
                    cout << endl;
                }
            }
            else{
                if (compare[i].first->val != -1) test += compare[i].second;
            }
            cout << compare[i].first->val << ", " << compare[i].second << endl;
            if (compare[i].first->val != -1) count++;
            test3++;
        }

        delete tmp;
        return true;
    }
};

int main() {
    //root³ëµå
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

    //TreeNode* root = new TreeNode(1);
    //root->left = new TreeNode(2);
    //root->right = new TreeNode(2);
    //root->left->right = new TreeNode(3);
    //root->right->right = new TreeNode(3);

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