#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
public:
    string val;
    vector<Node*> children;

    Node() {}
    ~Node() { children.clear(); }

    Node(string _val) {
        val = _val;
    }

    Node(string _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void NodeBfs(Node* root) {
    vector<vector<string>> t;
    vector<string> v;

    queue<Node*> q;
    Node* tmp;

    q.push(root);
    //cout << q.front()->val << endl;
    t.push_back({ q.front()->val });
    while (!q.empty()) {
        tmp = root;        
        if (q.front()->children.size() > 0) {
            for (int i = 0; i < q.front()->children.size(); i++) {
                //cout << q.front()->children[i]->val << endl;
                v.push_back(q.front()->children[i]->val);
                q.push(q.front()->children[i]);
            }
        }
        else {
            v.push_back("null");
        }
        t.push_back(v);
        v.clear();
        q.pop();
    }
    
    //int cnt = 1;
    //for (int i = 0; i < t.size(); i++) {
    //    for (int j = 0; j < t[i].size(); j++) {
    //        cout << t[i][j];
    //    }
    //    cout << endl;
    //    /*if (i == 0) cnt = 1;
    //    else if (i == 1) cnt = 2;
    //    else cnt *= cnt;

    //    if(i == 0 || i == 1) cout << endl;
    //    else {
    //        if (i * i == cnt) {
    //            cout << endl;
    //        }
    //    }*/
    //}
}

void NodeDfs(Node* root) {
    for (int i = 0; i < root->children.size(); i++) {
        NodeDfs(root->children[i]);
        cout << root->val << endl;
    }
}

void Run(Node* root) {
    NodeDfs(root);
}

//==============================

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(char x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//전위탐색
void preOrder(TreeNode* root) {
    cout << root->val << "\n";
    if (root->left != NULL) {
        preOrder(root->left);
    }
    if (root->right != NULL) {
        preOrder(root->right);
    }
}
//중위탐색
void inOrder(TreeNode* root) {
    if (root->left != NULL) {
        preOrder(root->left);
    }
    cout << root->val << "\n";
    if (root->right != NULL) {
        preOrder(root->right);
    }
}
//후위탐색
void postOrder(TreeNode* root) {
    if (root->left != NULL) {
        preOrder(root->left);
    }
    if (root->right != NULL) {
        preOrder(root->right);
    }
    cout << root->val << "\n";
}

//깊이우선탐색
void bfs(TreeNode* root) {
    queue<TreeNode*> q;
    TreeNode* tmp;
    int startPnt = 0;

    tmp = root;
    q.push(tmp);

    while (!q.empty()) {
        tmp = q.front();
        cout << q.front()->val << "\n";
        q.pop();
        if (tmp->left != nullptr) {
            q.push(tmp->left);
        }
        if (tmp->right != nullptr) {
            q.push(tmp->right);
        }
    }
    delete tmp;
}

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

//시간복잡도 : O(n^2) + O(n) ?
//공간복잡도 : O(n) ?

vector<char> b;
bool lLast = false;
bool posFirst = false;

void first(TreeNode* root) {
    if (lLast == false) {
        cout << root->val << " ";
    }

    //left edge iterative
    if (root->left != NULL) {
        first(root->left);
    }
    else {
        if (root->right != NULL) {
            first(root->right);
        }
        else {
            if (lLast == false) {
                lLast = true;
                posFirst = true;
            }
        }
    }
    if (root->right != NULL) {
        first(root->right);
    }
    else {
        if (root->left == NULL) {
            if (posFirst == true) {
                posFirst = false;
            }
            else {
                cout << root->val << " ";
            }
        }
    }
}

void second(TreeNode* root) {
    if (lLast == false) {
        b.push_back(root->val);
    }
    else {
        lLast = false;
    }
    if (root->right != NULL) {
        second(root->right);
    }
    else {
        if (root->left != NULL) {
            second(root->left);
        }
    }
}

void run(TreeNode* root) {
    first(root);
    second(root);
    reverse(b.begin(), b.end());
    for (int i = 1; i < b.size(); i++) {
        cout << b[i] << " ";
    }
}

int main() {
    //Node* root = new Node("a");
    //root->children = { new Node("b"), new Node("c") };
    //root->children[0]->children = { new Node("d"), new Node("e") };
    //root->children[1]->children = { new Node("f"), new Node("g") };

    //root->children[0]->children[0]->children = { new Node("h"), new Node("i") };
    //root->children[0]->children[1]->children = { new Node("j"), new Node("k") };
    //root->children[1]->children[0]->children = { new Node("l"), new Node("m") };
    //root->children[1]->children[1]->children = { new Node("n"), new Node("o") };

    //root->children[0]->children[1]->children[0]->children = { new Node("p") };
    //root->children[0]->children[0]->children[0]->children = { new Node("q") };

    //Run(root);

    //delete root;

    // Input
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