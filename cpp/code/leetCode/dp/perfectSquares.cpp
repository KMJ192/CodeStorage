#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
  int numSquares(int n) {   
    vector<int> table(n+1, 0);
    for (int i = 1; i <= n; i++) {
      table[i] = table[i - 1] + 1;
    }

    int curSquare = 2;
    while (curSquare*curSquare <= n) {
      int startIdx = curSquare * curSquare;
      table[startIdx] = 1;
      for (int i = startIdx + 1; i <= n; i++) {
        table[i] = min(table[i], table[i - startIdx] + 1);
      }

      curSquare++;
    }
    return table[n];
  }
};

int main() {
  Solution s;
  cout << s.numSquares(12);
  return 0;
}