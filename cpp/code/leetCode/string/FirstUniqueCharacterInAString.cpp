#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() == 1) return 0;
        using ii = pair<int, int>;
        int idx = -1;
        map<char, ii> m;

        for (int i = 0; i < s.size(); i++) {
            m[s[i]].first = i;
            m[s[i]].second++;
        }
        for (map<char, ii>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->second.second == 1) {
                if (idx == -1) idx = it->second.first;
                else idx = min(it->second.first, idx);
            }
        }
        return idx;
    }
};

int main() {
    Solution s;
    cout << s.firstUniqChar("aabb") << endl;

    return 0;
}