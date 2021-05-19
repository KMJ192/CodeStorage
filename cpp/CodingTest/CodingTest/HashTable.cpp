#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    string key;
    int value;
    Node* nextNode;
public:
    Node() : key(""), value(0), nextNode(NULL) {}
    Node(string _key, int _value) {
        key = _key;
        value = _value;
        nextNode = NULL;
    }
    Node* getNext() { return nextNode; }
    void setNext(Node* next) { nextNode = next; }
    string getKey() { return key; }
    int getValue() { return value; }
};

class HashTable {
private:
    int size;
    Node* nodeList;

    int hashFunction(string s) {
        int len = s.length();
        int hash = 0;
        for (int i = 0; i < len; i++) {
            hash += s[i];
        }
        return hash % size;
    }

public:
    HashTable(int _size) {
        size = _size;
        nodeList = new Node[_size];
    }

    ~HashTable() {
        for (int i = 0; i < size; i++) {
            Node* cur = nodeList[i].getNext();
            while (cur != NULL) {
                Node* temp = cur->getNext();
                delete cur;
                cur = temp;
            }
        }
        delete[] nodeList;
    }

    void put(string key, int value) {
        int index = hashFunction(key);
        Node* next = nodeList[index].getNext();
        Node* cur = &nodeList[index];
        while (next != NULL) {
            cur = next;
            next = next->getNext();
        }
        Node* newNode = new Node(key, value);
        cur->setNext(newNode);
    }

    Node get(string key) {
        int index = hashFunction(key);
        Node* cur = nodeList[index].getNext();
        while (cur != NULL) {
            if (!key.compare(cur->getKey())) {
                return *cur;
            }
            cur = cur->getNext();
        }
        return Node();
    }
};

int main(void){
    HashTable hashTable = HashTable(100);
    hashTable.put("ac", 10);
    hashTable.put("bb", 12);
    cout << hashTable.get("ac").getValue() << '\n';
    cout << hashTable.get("bb").getValue() << '\n';
    return 0;
}