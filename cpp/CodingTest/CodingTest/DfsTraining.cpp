//1. left edge 탐색 -> dfs 사용
//  - root node에서 시작
//  - left node가 있는지 없는지 확인 후 있으면 left node출력
//  - left node가 없을 경우 rigth node출력
//  - left/right node가 모두 없을 경우 left edge탐색 완료

//2. bottom edge 탐색
// - 1번 로직을 계속 진행하면서 최하단 node를 만나면 출력

//3. 1번/2번 logic이 종료된 후 다른 logic으로 실행
//  - root node에서 시작
//  - right node가 있는지 없는지 확인 후 있으면 rigth node를 vector배열에 push
//  - rigth node가 없으면 left node를 vector배열에 push
//  - 최하단 node를 만나면 종료
//  - vector를 reverse
//  - 1번 원소부터 마지막 원소까지 출력

//시간복잡도 : O(n^2) + O(3n) ?
//공간복잡도 : O(n) ?
#include<iostream>
#include<vector>

using namespace std;
//이진트리 구조체
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

vector<char> b;
bool lLast = false; //왼쪽 가장자리의 마지막 node임을 구분
bool posFirst = false; //bottom 가장자리의 첫번째 node임을 구분

void first(TreeNode* root) {
    //left가장자리 탐색
    //lLast가 true일 경우 left가장자리의 node는 모두 순회를 마침
    if (lLast == false) cout << root->val << " ";

    if (root->left != NULL) first(root->left);
    else {
        if (root->right != NULL) first(root->right);
        else {
            if (lLast == false) {
                //현재 노드의 left/right가 모두 null이므로
                //left를 출력하지 않기 위해 lLast를 true로 설정 
                lLast = true;
                posFirst = true;
            }
        }
    }
    //bottom의 가장자리 탐색 
    if (root->right != NULL) first(root->right);
    else {
        if (root->left == NULL) {
            if (posFirst == true) posFirst = false;
            else cout << root->val << " ";
        }
    }
}

void second(TreeNode* root) {
    //lLast가 true일 경우 root node를 가리키고 있으므로
    //출력 대상에서 제외
    if (lLast == false) b.push_back(root->val);
    else lLast = false;
    if (root->right != NULL) second(root->right);
    else {
        if (root->left != NULL) second(root->left);
    }
}
//first함수와 second함수를 실행
void run(TreeNode* root) {
    if (root == nullptr) return;
    first(root);
    second(root);
    //second함수에서 실행한 결과인 vector b를 reverse
    reverse(b.begin(), b.end());
    //0번째 원소는 출력 대상에서 제외
    for (int i = 1; i < b.size(); i++) {
        cout << b[i] << " ";
    }
}
//main function에서 input
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
    root->right->left->left->left = new TreeNode('q');

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