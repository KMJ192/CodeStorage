/*
  // 8: 28 ~ 8: 58
  I
    - integer type 2d-array
  O
    - merged integer type 2d-array
  E
    - 배열 길이가 없다 -> out 빈 배열
  S
    1. 배열 sorting -> 각 원소 별 첫번째 원소 기준
    2. 현재 인덱스의 원소 그당므 인덱스의 원소 비교
      - 현재의 두번째 다음의 첫번째 -> 현재의 두번째가 더 크다. -> merge
      - 현재의 두번째 다음의 두번째 비교해서 큰거를 범위
      - [현재의 첫번째, 큰거]
      [[1,4], [2,6], [3,5]]
      [[1,6]]
    3. 반복

  Time : O(n)
  Space : O(n)


  Problem Statement #
  Given a list of intervals, merge all the overlapping intervals to produce a list that has only 
  mutually exclusive intervals.

  Example 1:

  Intervals: [[1,4], [2,5], [7,9]]
  Output: [[1,5], [7,9]]
  Explanation: Since the first two intervals [1,4] and [2,5] overlap, we merged them into 
  one [1,5].

  Example 2:

  Intervals: [[6,7], [2,4], [5,9]]
  Output: [[2,4], [5,9]]
  Explanation: Since the intervals [6,7] and [5,9] overlap, we merged them into one [5,9].

  Example 3:

  Intervals: [[1,4], [2,6], [3,5]]
  Output: [[1,6]]
  Explanation: Since all the given intervals overlap, we merged them into one.


    1. 배열 sorting -> 각 원소 별 첫번째 원소 기준
    2. 현재 인덱스의 원소 그당므 인덱스의 원소 비교
      - 현재의 두번째 다음의 첫번째 -> 현재의 두번째가 더 크다. -> merge
      - 현재의 두번째 다음의 두번째 비교해서 큰거를 범위
      - [현재의 첫번째, 큰거]
      q => [[1,5]]
      [[1,5]]
    3. 반복

  Time : O(n)
  Space : O(n)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
private:
  vector<vector<int>> retVal;
public:
  void mergeData(vector<vector<int>>& object) {
    if (object.size() == 0) return; // base case
    int arrLen = object.size();

    // reverse priority_queue => 우선순위의 반대로 저장되는 큐, 
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;

    // q push
    for (int i = 0; i < arrLen; i++) {
      q.push(object[i]);
    }

    // 데이터 merge
    while (!q.empty()) {
      vector<int> prev = { q.top()[0],  q.top()[1] };
      q.pop();
      if (q.empty()) {
        retVal.push_back(prev);
        break;
      }
      vector<int> next = { q.top()[0],  q.top()[1] };
      if (prev[1] >= next[0]) {
        // merge 대상이면 q에서 pop
        q.pop();
        // 각각 최소, 최대값을 저장
        int n = min(prev[0], next[0]);
        int m = max(prev[1], next[1]);
        q.push({ n, m });
      } else {
        retVal.push_back(prev);
      }
    }
  }

  vector<vector<int>> result() {
    return retVal;
  }
};

int main() {
  vector<vector<int>> object = {
    {1,4},
    {2,6},
    {3,6}
  };
  Solution s;
  s.mergeData(object);
  
  vector<vector<int>> retValue = s.result();

  for(vector<int> o : retValue) {
    cout << o[0] << ", " << o[1] << endl;
  }

  return 0;
}