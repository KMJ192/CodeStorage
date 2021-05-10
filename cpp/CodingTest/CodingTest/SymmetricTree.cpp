#include<iostream>
#include<queue>
#include<vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Input: (ex) : [2, 3, 3, 4, null, nul, 4, null, 5, 5, null, null, 6, 6, null, 7, 8, 8, 7, 9, 0, 0, 1, 1, 0, 0, 9]
//Output: true
//Constraints :
// 1) The number of nodes in the tree is in the ragne[1, 1000]
// 2) -100 <= Node.val <= 100
//Edge Case :
// 1) tree == null
//brute force : naive
//  BFS풀이
//  time : 
//  space
//code :
class Solution {
private:
    queue<TreeNode*> coolTime;
    vector<TreeNode*> compare;
    vector<int> v;
public:
    Solution() {}
    ~Solution() {}

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        else if (root->left == nullptr && root->right == nullptr) return true;
        else if (root->left == nullptr || root->right == nullptr) return false;

        TreeNode* tmp;
        tmp = root;

        //BFS풀이를 위한 q
        coolTime.push(tmp);
        //모든 node를 push할 compare vector
        //null일 경우 -1을 저장하고 null이 아니면 tree의 value를 저장
        compare.push_back(tmp);
        while (!coolTime.empty()) {
            tmp = coolTime.front();
            coolTime.pop();
            if (tmp->left != nullptr) {
                coolTime.push(tmp->left);
                compare.push_back(tmp->left);
            }
            else compare.push_back(new TreeNode(-1));
            if (tmp->right != nullptr) {
                coolTime.push(tmp->right);
                compare.push_back(tmp->right);
            }
            else compare.push_back(new TreeNode(-1));
        }
        //보장되는 반복횟수 저장(node하나에 2번의 반복문을 보장하여야 함.)
        int loopGuarantee = 2; 
        int node = 0, count = 0;
        cout << compare[0]->val << endl;
        for (int i = 1; i < compare.size(); i++) {
            count++; //반복횟수를 센다
            v.push_back(compare[i]->val);
            if (compare[i]->val != -1) node++; //해당 node가 null이 아닐 경우 node를 카운팅한다(반복문을 보장하기 위함)
            if (count == loopGuarantee) { 
                loopGuarantee = node * 2; //node의 갯수 * 2 만큼 다음 반복을 보장하기위함
                count = 0;                         //count와 node의 갯수를 초기화 시킴(다음 level을 가리키기 위함)
                node = 0;
                for (int j = 0; j < v.size() / 2; j++) {
                    cout << v[j] << ", " << v[v.size() - j - 1] << endl;
                    if (v[j] != v[v.size() - j - 1]) return false; //벡터의 n번째와 벡터의 크기 - n 번째 값을 비교하여 틀릴 경우 false를 반환
                }
                //for (int j = 0; j < v.size(); j++) {
                //    cout << v[j] << " ";
                //    //if (v[j] != v[v.size() - j - 1]) return false; //벡터의 n번째와 벡터의 크기 - n 번째 값을 비교하여 틀릴 경우 false를 반환
                //}
                cout << endl;
                v.clear();
            }
        }

        delete tmp;
        return true; //모든 노드가 일치하였기 때문에 true반환
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

    /*TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3);*/

    Solution s;
    cout << s.isSymmetric(root);

    delete root;

    return 0;
}