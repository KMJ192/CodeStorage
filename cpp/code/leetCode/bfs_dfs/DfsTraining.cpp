//1. left edge Ž�� -> dfs ���
//  - root node���� ����
//  - left node�� �ִ��� ������ Ȯ�� �� ������ left node���
//  - left node�� ���� ��� rigth node���
//  - left/right node�� ��� ���� ��� left edgeŽ�� �Ϸ�

//2. bottom edge Ž��
// - 1�� ������ ��� �����ϸ鼭 ���ϴ� node�� ������ ���

//3. 1��/2�� logic�� ����� �� �ٸ� logic���� ����
//  - root node���� ����
//  - right node�� �ִ��� ������ Ȯ�� �� ������ rigth node�� vector�迭�� push
//  - rigth node�� ������ left node�� vector�迭�� push
//  - ���ϴ� node�� ������ ����
//  - vector�� reverse
//  - 1�� ���Һ��� ������ ���ұ��� ���

//�ð����⵵ : O(n^2) + O(3n) ?
//�������⵵ : O(n) ?
#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;
//����Ʈ�� ����ü
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

vector<char> b;
bool lLast = false; //���� �����ڸ��� ������ node���� ����
bool posFirst = false; //bottom �����ڸ��� ù��° node���� ����
bool toggle = false;//����node�϶� false, ������ node�϶� true

void first(TreeNode* root) {
    //left�����ڸ� Ž��
    //lLast�� true�� ��� left�����ڸ��� node�� ��� ��ȸ�� ��ħ
    if (lLast == false) cout << root->val << " ";

    if (root->left != NULL) first(root->left);
    else {
        if (root->right != NULL) {
            toggle = true;
            first(root->right);
        }
        else {
            if (lLast == false) {
                //���� ����� left/right�� ��� null�̹Ƿ�
                //left�� ������� �ʱ� ���� lLast�� true�� ���� 
                lLast = true;
                posFirst = true;
            }
        }
    }
    //bottom�� �����ڸ� Ž�� 
    if (root->right != NULL) first(root->right);
    else {
        if (root->left == NULL) {
            if (posFirst == true) posFirst = false;
            else if(toggle == true) toggle = false;
            else cout << root->val << " ";
        }
    }
}

void second(TreeNode* root) {
    //lLast�� true�� ��� root node�� ����Ű�� �����Ƿ�
    //��� ��󿡼� ����
    if (lLast == false) b.push_back(root->val);
    else lLast = false;
    if (root->right != NULL) second(root->right);
    else {
        if (root->left != NULL) second(root->left);
    }
}
//first�Լ��� second�Լ��� ����
void run(TreeNode* root) {
    if (root == nullptr) return;
    first(root);
    second(root);
    //second�Լ����� ������ ����� vector b�� reverse
    reverse(b.begin(), b.end());
    //0��° ���Ҵ� ��� ��󿡼� ����
    for (int i = 1; i < b.size(); i++) {
        cout << b[i] << " ";
    }
}
//main function���� input
int main() {
    //tree input
    TreeNode* root = new TreeNode('a');
    root->left = new TreeNode('b');
    root->right = new TreeNode('c');
    root->left->left = new TreeNode('d');
    root->left->right = new TreeNode('e');
    root->right->left = new TreeNode('f');
    root->right->right = new TreeNode('g');
    root->left->left->left = new TreeNode('h');
    root->left->left->right = new TreeNode('i');
    root->left->right->left = new TreeNode('j');
    root->left->right->right = new TreeNode('k');
    root->right->left->left = new TreeNode('l');
    root->right->left->right = new TreeNode('m');
    root->right->right->left = new TreeNode('n');
    root->right->right->right = new TreeNode('o');
    root->left->right->left->left = new TreeNode('p');
    root->right->left->left->right = new TreeNode('q');

    run(root);

    delete root;
    return 0;
}

//Input:
//  Output: return value

//Constraints :
//  1) num of nodes,
//  2) node value = pos or neg
//Edge Case :
//  1) tree == = null, return root;

//brute force : naive
//  DFS or BFS or iteratively or recursive
//  time, space
//optimal solution
//  algorithmand Data structure
//  time, space

//code :
//  function