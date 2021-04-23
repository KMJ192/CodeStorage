#include<iostream>
#include<sstream>
#include<vector>
#include<map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    map<string, string> m;

public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        if(digits == "") return answer;

        m.insert(pair<string, string>("2", "a.d.c"));
        m.insert(pair<string, string>("3", "d.e.f"));
        m.insert(pair<string, string>("4", "g.h.i"));
        m.insert(pair<string, string>("5", "j.k.l"));
        m.insert(pair<string, string>("6", "m.n.o"));
        m.insert(pair<string, string>("7", "p.q.r.s"));
        m.insert(pair<string, string>("8", "t.u.v"));
        m.insert(pair<string, string>("9", "w.x.y.z"));
        
        vector<vector<string>> map;
        for (int i = 0; i < digits.size(); i++) {
            vector<string> tmp = splitString(digits, '.');
            map.push_back(tmp);
        }
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map[i].size(); i++) {
                cout << map[i][j] << endl;
            }
        }


        return answer;
    }

    vector<string> splitString(string object, char delimeter) {
        vector<string> re;
        re.clear();
        string buffer;
        istringstream ss(object);
        while (getline(ss, buffer, delimeter)) {
            re.push_back(buffer);
        }
        return re;
    }
};

int main() {
    Solution s;
    s.letterCombinations("23");

    return 0;
}