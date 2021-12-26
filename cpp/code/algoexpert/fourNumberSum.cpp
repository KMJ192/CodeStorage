#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
  using ii = pair<int, int>;
  vector<vector<int>> answer;
public:
  void fourNumberSum(vector<int> array, int targetSum) {
    if (array.size() < 4) return;
    int len = (int)array.size();

    set<vector<int>> s;

    sort(array.begin(), array.end());

    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++){
        ii pointer = ii(j + 1, len - 1);
        int sum = targetSum - array[i] - array[j];
        
        while (pointer.first < pointer.second) {
          cout << array[i] << array[j] << array[pointer.first] << array[pointer.second] << "\n";
          if (array[pointer.first] + array[pointer.second] < sum) {
            pointer.first++;
            continue;
          }

          if (array[pointer.first] + array[pointer.second] > sum) {
            pointer.second--;
            continue;
          }

          s.insert({ array[i], array[j], array[pointer.first], array[pointer.second]});

          pointer.first++;
          pointer.second--;
        }
      }
    }    

    vector<vector<int>> v(s.begin(), s.end());
    for (vector<int> ele : v) {
      for (int unit : ele) {
        cout << unit << " ";
      }
      cout << "\n";
    }
  }
};

int main() {
  Solution s;
  vector<int> array = { 7, 6, 4, -1, 1, 2 };

  s.fourNumberSum(array, 16);

  return 0;
}