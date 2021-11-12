/*
  20:32 ~ 21:02

i: integer type
o: number에 맞는 column
constraint : 1 <= columnNumber <= 2^31 - 1
edge

algo
  brute force
ds
  string
sd
  701
  A ~ Z
  z -> 26

  AA ~ ZZ => 701
  zz -> 26 * 26 + 26 => 702

  AAA ~ ZZZ
  zzz -> (26 * 26 + 26) * 26 + 26

time: O(n)
space: O(n)
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
      string answer;
      while (columnNumber) {
        columnNumber--;
        int z = columnNumber % 26;
        char c = 'A' + z;
        answer.push_back(c);
        columnNumber /= 26;
      }
      reverse(answer.begin(), answer.end());
      return answer;
    }
};

int main() {
  Solution s;
  s.convertToTitle(701);
  return 0;
}