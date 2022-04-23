/**
 * https://leetcode.com/problems/edit-distance/
 * @file editDistance.cpp
 * @author MyeongJun Kim (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * input: {string} word1, {string} word2
 * output: int
 * constraint
 *   - 0 <= word1.length, word2.length <= 500
 *   - word1, word2 => lowercase english letters
 * word1, word2가 주어진다.
 * word1에서 word2로 만들 수 있는 최소한의 작업숫자를 구할것
 * word에 대한 가능한 작업
 * Insert a character
 * Delete a character
 * Replace a character
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
private:
  int dp[501][501];
public:
  int minDistance(string word1, string word2) {
    // dp를 -1로 채워줌
    memset(dp, -1, sizeof(dp));
    return calc(word1, word2, word1.size() - 1, word2.size() - 1);
  }

  int calc(string &word1, string &word2, int i, int j) {
    if (i < 0 || j < 0) {
      // cout << "i : " << i << ", j : " << j << endl;
      if (i < 0 && j < 0) return 0;
      if (i < 0) return j + 1;
      return i + 1;
    }

    if (dp[i][j] != -1) return dp[i][j];

    if (word1[i] == word2[j]) {
      dp[i][j] = calc(word1, word2, i - 1, j - 1);
    } else {
      dp[i][j] = 1 + min({calc(word1, word2, i - 1, j), calc(word1, word2, i - 1, j - 1), calc(word1, word2, i, j - 1)});
    }

    cout << "i : " << i << ", j : " << j << endl;
    return dp[i][j];
  }
};

int main() {
  Solution s;

  cout << s.minDistance("intention", "execution") << endl;

  return 0;
}