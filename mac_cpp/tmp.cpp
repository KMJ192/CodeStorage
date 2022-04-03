/**
 * https://leetcode.com/problems/shortest-palindrome/
 * @file ShortestPalindrom.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 * kmp solution
 * 
 */

#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

class Solution {
public:
  string shortestPalindrome(string s) {
    int sLen = s.length();
    string answer(s);
    reverse(answer.begin(), answer.end());
    string tmp = s + "#" + answer;
    // tmp = abcd#bcda
    int maxLen = tmp.length();
    vector<int> f(maxLen, 0);

    // abcd
    /*
      a b c d

    i     ↓
      a b c d # b c d a
    t ↑

    f 0 0 0 0 0 0 0 0 0
    */

    int i = 1;
    while (i < maxLen) {
      int t = f[i - 1];
      while (tmp[i] != tmp[t]) {
        if (t > 0) {
          t = f[t - 1];
        } else {
          f[i] = 0;
          i++;
          continue;
        }
      }
      if (tmp[i] == tmp[t]) {
        t++;
        f[i] = t;
      }
      i++;
    }

    return answer.substr(0, sLen - f[maxLen - 1]) + s;

    return answer;
  }
};

int main() {
  Solution s;

  cout << s.shortestPalindrome("abcd") << endl;

  return 0;
}