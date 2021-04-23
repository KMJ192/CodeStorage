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
private:
    vector<Node*> v;
    priority_queue<int> last;
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        return dfs(root, 1);
    }
    int dfs(Node* root, int max) {
        Node* tmp;
        if (!last.empty()) {
            if (last.top() < max) {
                last.push(max);
            }
        }
        else {
            last.push(max);
        }
        for (int i = 0; i < root->children.size(); i++) {
            tmp = root->children[i];
            dfs(tmp, max + 1);
        }

        return last.top();
    }
    ~Solution() {
        while (!last.empty()) {
            last.pop();
        }
    }
};

int main() {

    Node* root = new Node(1);
    root->children = { new Node(2), new Node(3), new Node(4), new Node(5) };

    root->children[1]->children = { new Node(6), new Node(7) };

    root->children[1]->children[1]->children = { new Node(11) };
    root->children[1]->children[1]->children[0]->children = { new Node(14) };

    root->children[2]->children = { new Node(8) };
    root->children[2]->children[0]->children = { new Node(12) };

    root->children[3]->children = { new Node(9), new Node(10) };

    root->children[3]->children[0]->children = { new Node(13) };    
    
        
    Solution s;
    cout << s.maxDepth(root);

    delete root;

	return 0;
}