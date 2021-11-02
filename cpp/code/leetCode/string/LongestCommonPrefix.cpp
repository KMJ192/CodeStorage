#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];

        string answer;
        for (int i = 0; i < (int)strs[0].size(); i++) {
            int count = 0;
            char c = strs[0][i];
            for (int j = 0; j < (int)strs.size(); j++) {
                if (c != strs[j][i]) return answer;
            }
            answer.push_back(c);
        }

        return answer;
    }
};

int main() {

    Solution s;
    vector<string> strs = { "dog","abcdog","saddog" };
    cout << s.longestCommonPrefix(strs) << endl;

    return 0;
}