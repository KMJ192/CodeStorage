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

//����Ž��
void preOrder(TreeNode* root) {
    cout << root->val << "\n";
    if (root->left != NULL) {
        preOrder(root->left);
    }
    if (root->right != NULL) {
        preOrder(root->right);
    }
}
//����Ž��
void inOrder(TreeNode* root) {
    if (root->left != NULL) {
        preOrder(root->left);
    }
    cout << root->val << "\n";
    if (root->right != NULL) {
        preOrder(root->right);
    }
}
//����Ž��
void postOrder(TreeNode* root) {
    if (root->left != NULL) {
        preOrder(root->left);
    }
    if (root->right != NULL) {
        preOrder(root->right);
    }
    cout << root->val << "\n";
}

//���̿켱Ž��
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

//�ð����⵵ : O(n^2) + O(n) ?
//�������⵵ : O(n) ?

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