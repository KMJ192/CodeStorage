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
        
        TreeNode* tmp;
        int startPnt = 0;

        tmp = root;
        q.push(tmp);
        v.push_back(to_string(tmp->val));
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            if (tmp->left != nullptr) {
                q.push(tmp->left);
                v.push_back(to_string(tmp->left->val));
            }
            else {
                v.push_back("null");
            }
            if (tmp->right != nullptr) {
                q.push(tmp->right);
                v.push_back(to_string(tmp->right->val));
            }
            else {
                v.push_back("null");
            }
        }

        int cnt = 2;
        int pos = 1;
        vector<string> test;
        for (int i = 1; i < v.size(); i++) {
            if (i == pos) {
                test.clear();
                //pos에 다음 포지션 입력
                if (cnt == 2) {
                    pos = cnt + 1;
                    cnt *= 2;
                }
                else {
                    pos = cnt + pos;
                    cnt *= 2;
                }

                //다음을 가리키고 있는 위치값이 v보다 클 경우 종료
                if (pos > v.size() - 1) {
                    break;
                }

                for (int j = i; j < pos; j++) {
                    test.push_back(v[j]);
                }
                for (int j = 0; j < test.size() / 2; j++) {
                    cout << test[j] << test[test.size() - 1 - j] << endl;
                    if (test[j] != test[test.size() - 1 - j]) {
                        return false;
                    }
                }
            }
        }

        delete tmp;
        return true;
    }
};


int main() {
    //root노드
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->right = new TreeNode(3);
    root->right->left= new TreeNode(3);

    Solution s;
    cout << s.isSymmetric(root) << endl;

    delete root;

    return 0;
}
