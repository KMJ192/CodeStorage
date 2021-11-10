#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

// A => 1
// Z => 26
// AA => 27
// BC => (26 * 2) + 3 => 55
// BZ => (26 * 2) + 26
// ZZ => (26 * 26) + 26 = 702
// ABC => ((26 * 26) + 26) + (26 * 1) + 3
// ACC => ((26 * 26) + 26) + (26 * 2) + 3
// ZZZ => (702 * 26) + 26 = 18278
// ACBC => ((18278 * 1) + 26) + ((702 * 2) + 26) + (26 * 2) + 3
// ZZZZ => 18278 * 26 + 26

// ACBC
// 26^3 * 1 + 26^2 * 3 + 26^1 * 2 + 26^0 + 3
// 17576 + 2028 + 52 + 3

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int answer = 0, cnt = columnTitle.size() - 1;
        for (int i = 0; i < columnTitle.size(); i++) {
            // cout << columnTitle[i] - 'A' + 1 << endl;
            // cout << pow(26, cnt) * (columnTitle[i] - 'A' + 1) << endl;
            answer += (pow(26, cnt) * (columnTitle[i] - 'A' + 1));
            cnt--;
        }

        return answer;
    }
};

int main() {

    Solution s;
    cout << s.titleToNumber("ACBC") << endl;
    return 0;
}