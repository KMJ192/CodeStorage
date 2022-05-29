#include <iostream>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    long long y = 0;
    while (x) {
      y = y * 10 + (x % 10);
      x /= 10;
    }

    if(y > INT_MAX || y < INT_MIN) {
      return 0;
    }
    
    return y;
  }
};

int main() {
  Solution s;

  cout << s.reverse(123);

  return 0;
}