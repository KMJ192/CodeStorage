#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    bool isWord;
    string word;
    unordered_map<char, Node*> next;

    Node() {
        isWord = false;
    };
    ~Node() { next.clear(); }
};

class Trie {
private:
    Node* root;
public:
    void insert(string word) {
        Node* curNode = root;
        for (int i = 0; i < (int)word.size(); i++) {
            char c = word[i];
            if (curNode->next.count(c)) {
                curNode = curNode->next[c];
            }
            else {
                Node* n = new Node();
                n->word = c;
                curNode->next[c] = n;
                curNode = n;
            }
        }
        curNode->isWord = true;
    }

    bool search(string word) {
        Node* curNode = root;
        for (int i = 0; i < (int)word.size(); i++) {
            char c = word[i];
            curNode = curNode->next[c];
            if (!curNode) return false;
        }
        return curNode->isWord;
    }

    bool startWith(string prefix) {
        Node* curNode = root;
        for (int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];
            curNode = curNode->next[c];
            if (!curNode) return false;
        }
        return true;
    }

    Trie() {
        root = new Node();
    }
    ~Trie() {
        delete root;
    }
};

int main() {
    Trie* trie = new Trie();
    trie->insert("app");
    trie->insert("apple");
    trie->insert("application");
    cout << trie->search("appl") << "\n";
    cout << trie->startWith("applicac") << "\n";

    return 0;
}