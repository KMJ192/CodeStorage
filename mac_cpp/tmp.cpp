#include <iostream>
#include <unistd.h>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows <= 1) return s;
    string answer = "";
    int sLen = s.length();
    for (int i = 0; i < numRows; i++) {
      int increment = 2 * (numRows - 1);
      for (int j = i; j < sLen; j += increment) {
        answer += s[j];
        if (i > 0 && i < (numRows - 1) && (j + increment - 2 * i) < sLen) {
          answer += s[j + increment - 2 * i];
        }
      }
    }
    return answer;
  }
};

int main() {
  string s = "PAYPALISHIRING";
  Solution so;
  cout << so.convert(s, 3);
  
  return 0;
}