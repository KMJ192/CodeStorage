#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> input, int k) {
  vector<int> answer;
  if (input.size() == 0) return answer;

  sort(input.begin(), input.end());

  int iLen = input.size();
  int tmp = input[0];

  // 시간복잡도 -> O(K + N)
  // 공간 -> O(K)
  // [-10, 1, 2, 3]
  // tmp = -10
  int test = 1;
  while (test < tmp) {
    if (answer.size() == k) break;
    answer.push_back(test++);
  }

  for (int i = 1; i < iLen; i++) {
    if (input[i] < 0) {
      tmp = input[i];
      continue;
    }
    for (int j = tmp + 1; j < input[i]; j++) {
      if (j > 0) {
        answer.push_back(j);
      }
      if (answer.size() == k) break;
    }
    tmp = input[i];
    if (answer.size() == k) break;
  }

  int now = answer.size();
  int next = input[iLen - 1];
  int i = 1;
  while (now < k) {
    answer.push_back(next + i);
    if (answer.size() == k) break;
    i++;
    now++;
  }

  return answer;
}

int main() {
  vector<int> input = { 2, 3, 6 };
  vector<int> answer = solution(input, 5);
  for(int i = 0; i < answer.size(); i++) {
    cout << answer[i] << endl;
  }
  return 0;
}