#include<iostream>
#include<vector>
using namespace std;

class MyHashMap {
private:
public:
    vector<pair<int, int>> map;
    MyHashMap() {}
    ~MyHashMap() { map.clear(); }

    void put(int key, int value) {
        if (get(key) == -1) map.push_back(pair<int, int>(key, value));
        else {
            remove(key);
            map.push_back(pair<int, int>(key, value));
        }
    }
    
    int get(int key) {
        for (int i = 0; i < map.size(); i++) {
            if(map[i].first == key) return map[i].second;
        }
        return -1;
    }
    
    void remove(int key) {
        for (int i = 0; i < map.size(); i++) {
            if (map[i].first == key) map.erase(map.begin() + i);
        }
    }
};

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    MyHashMap a;
    a.put(1, 1);
    a.put(2, 2);
    a.get(1);
    a.get(3);

    //cout << a.get(1) << endl; //output 1
    //cout << a.get(3) << endl; //output -1
    a.remove(3);


    return 0;
}