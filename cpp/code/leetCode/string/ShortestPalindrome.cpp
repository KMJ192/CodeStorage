#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string tmp1 = s + "#", tmp2 = s;
        reverse(tmp2.begin(), tmp2.end());
        tmp1 += tmp2;

        int n = tmp1.length();
        vector<int> pi(n, 0);

        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            cout << j << endl;
            while (j > 0 && tmp1[j] != tmp1[i]) {
                j = pi[j - 1];
            }

            cout << tmp1[j] << tmp1[i] << endl;
            if (tmp1[j] == tmp1[i]) j++;

            pi[i] = j;
        }

        string tot = s.substr(pi[n - 1]);
        reverse(tot.begin(), tot.end());

        return tot + s;
    }
};

int main() {
    Solution s;

    cout << s.shortestPalindrome("aacecaaa") << endl;

    return 0;
}