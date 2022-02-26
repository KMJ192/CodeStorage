#include <iostream>

using namespace std;

class Solution {
private:
  int a[4] = { 500, 100, 50, 10 };
public:
  int change(int money) {
    int count = 0;
    int tmp1 = money;
    int tmp2 = money;

    int i = 0;
    while (tmp1 > 0) {
      while (tmp1 < a[i]) {
        i += 1;
      }
      tmp1 %= a[i];
      tmp2 = tmp2 - tmp1;
      count += tmp2 / a[i];
      tmp2 = tmp1;
    }

    return count;
  }
};

// 2240 / 500
int main(){
  Solution s;
  cout << s.change(6720) << endl;
  return 0;
}

