#include<iostream>
#include<cassert>
#include<list>

using namespace std;

class MyHashSet {
public:
    //saved key
    list<int> set;
    MyHashSet() {}

    //add key
    void add(int key) {
        if (contains(key) == false) set.push_back(key);
        else throw "existe key";
    }

    //remove key
    void remove(int key) {
        set.remove(key);
    }

    //contains key
    bool contains(int key) {
        for (list<int>::iterator it = set.begin(); it != set.end(); it++) {
            if (*it == key) return true;
        }
        return false;
    }
    ~MyHashSet() {
        set.clear();
    }
};


int main() {

    MyHashSet myHashSet;
    myHashSet.add(1);
    myHashSet.add(2);
    //myHashSet.remove(2);
    

	return 0;
}