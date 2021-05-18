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
//  BFSǮ��
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

        //BFSǮ�̸� ���� q
        coolTime.push(tmp);
        //��� node�� push�� compare vector
        //null�� ��� -1�� �����ϰ� null�� �ƴϸ� tree�� value�� ����
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
        //����Ǵ� �ݺ�Ƚ�� ����(node�ϳ��� 2���� �ݺ����� �����Ͽ��� ��.)
        int loopGuarantee = 2; 
        int node = 0, count = 0;
        cout << compare[0]->val << endl;
        for (int i = 1; i < compare.size(); i++) {
            count++; //�ݺ�Ƚ���� ����
            v.push_back(compare[i]->val);
            if (compare[i]->val != -1) node++; //�ش� node�� null�� �ƴ� ��� node�� ī�����Ѵ�(�ݺ����� �����ϱ� ����)
            if (count == loopGuarantee) { 
                loopGuarantee = node * 2; //node�� ���� * 2 ��ŭ ���� �ݺ��� �����ϱ�����
                count = 0;                         //count�� node�� ������ �ʱ�ȭ ��Ŵ(���� level�� ����Ű�� ����)
                node = 0;
                for (int j = 0; j < v.size() / 2; j++) {
                    cout << v[j] << ", " << v[v.size() - j - 1] << endl;
                    if (v[j] != v[v.size() - j - 1]) return false; //������ n��°�� ������ ũ�� - n ��° ���� ���Ͽ� Ʋ�� ��� false�� ��ȯ
                }
                //for (int j = 0; j < v.size(); j++) {
                //    cout << v[j] << " ";
                //    //if (v[j] != v[v.size() - j - 1]) return false; //������ n��°�� ������ ũ�� - n ��° ���� ���Ͽ� Ʋ�� ��� false�� ��ȯ
                //}
                cout << endl;
                v.clear();
            }
        }

        delete tmp;
        return true; //��� ��尡 ��ġ�Ͽ��� ������ true��ȯ
    }
};

int main() {
    //root���
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