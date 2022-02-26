#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ii = pair<int, int>;
using iii = pair<int, ii>;

bool compare(const iii& a, const iii& b) {
  return a.second.second < b.second.second;
}

class Solution {
private:
vector<int> answer;
public:
  vector<int> subject(vector<iii>& classes) {
    greedy(classes);
    return answer;
  }

  void greedy(vector<iii>& classes) {
    sort(classes.begin(), classes.end(), compare);
    int prevTime = 0;
    for(iii value: classes) {
      int className = value.first;
      int nextTime = value.second.first;
      if (nextTime >= prevTime) {
        prevTime = value.second.second;
        answer.push_back(value.first);
      }
    }
  }
};

int main() {
  vector<iii> classes = {
    iii(0, ii(7, 8)),
    iii(1, ii(5, 7)),
    iii(2, ii(3, 5)),
    iii(3, ii(1, 2)),
    iii(4, ii(8, 10)),
    iii(5, ii(9, 11))
  };

  Solution s;
  s.subject(classes);

  return 0;
}