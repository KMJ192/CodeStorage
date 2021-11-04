#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        if (s.size() == 1) return s;
        int count = 0;
        int idx1 = 0;
        int idx2 = 1;
        string tmp = s;
        while (count < tmp.size()) {
            count++;
            if (idx2 < tmp.size() && tmp[idx1] == tmp[idx2]) {
                for (int i = idx2 + 1; i < tmp.size(); i++) {
                    if (tmp[idx1] != tmp[i]) break;
                    idx2++;
                }
                tmp = tmp.substr(0, idx1) + tmp.substr(idx2 + 1, tmp.size() - 1);
                idx1 = 0;
                idx2 = 1;
                count = 0;
            }
            else {
                idx1++;
                idx2++;
            }
        }
        return tmp;
    }
};

int main() {
    Solution s;
    cout << s.removeDuplicates("acbbbaaca");

    return 0;
}