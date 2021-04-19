#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    ~Node() { children.clear(); }

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//Node의 가장 최대 Depth를 구하기
class Solution {
public:
    int maxDepth(Node* root) {
        cout << root->val << endl;
        return 0;
    }
};

int main() {
    Node* d1 = new Node;
    vector<Node*> tmp;
    d1->val = 1;
    tmp.push_back(d1);
    d1->val = NULL;
    tmp.push_back(d1);
    d1->val = 2;
    tmp.push_back(d1);
    d1->val = 3;
    tmp.push_back(d1);
    d1->val = 4;
    tmp.push_back(d1);
    d1->val = NULL;
    tmp.push_back(d1);
    d1->val = 5;
    tmp.push_back(d1);
    d1->val = 6;
    tmp.push_back(d1);

    Node *root = new Node;
    root->children = tmp;
    
    Solution s;
    s.maxDepth(root);

	return 0;
}