#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    bool isWord;
    string word;
    unordered_map<char, Node*> next;
    Node() {
        word = "";
        isWord = false;
    }
    ~Node() { next.clear(); }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    ~Trie() {
        delete root;
    }

    void insert(string word) {
        Node* curNode = root;
        for (int i = 0; i < (int)word.size(); i++) {
            char c = word[i];
            cout << c << endl;
            if (curNode->next[c] == nullptr) {
                curNode->next[c] = new Node();
            }
            curNode = curNode->next[c];
        }
        if (!curNode->isWord) {
            curNode->word = word;
            curNode->isWord = true;
        }
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

    bool startsWith(string prefix) {
        Node* curNode = root;
        for (int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];
            curNode = curNode->next[c];
            if (!curNode) return false;
        }
        return true;
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