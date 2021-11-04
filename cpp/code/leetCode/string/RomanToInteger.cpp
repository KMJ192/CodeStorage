#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
    using si = pair<string, int>;
    map<string, int> pair = {
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000}
    };
public:
    int romanToInt(string s) {
        int count = 0;
        int i = 0;
        string tmp_string(1, s[0]);

        while (i < s.size()) {
            int j = i + 1;
            if (j < s.size()) {
                string first(1, s[i]);
                string second(1, s[j]);

                if (pair[first] > pair[first + second]) {
                    i++;
                    count += pair[first];
                }
                else {
                    i += 2;
                    count += pair[first + second];
                }
            }
            else {
                string tmp(1, s[i]);
                count += pair[tmp];
                i++;
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    cout << s.romanToInt("IV");

    return 0;
}