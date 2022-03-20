/**
 * @file tmp.cpp
 * @author MyeongJunKim (myeongjun222@github.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * Longest Valid Parentheses
 * 괄호 '(' , ')'로 이루어진 문자열을 주고 가장 긴 유효한 괄호 형식으로 된 문자열의 길이를 반ㅏㄴ
 * input : string type s
 * constraint
 *  - 0 ≤ s.length() ≤ 3 * 10^4
 *  - s[i] == '(' or ')'
 * 
 * solution
   ) ( ) ( ) )
   0 1 2 3 4 5
   st
   0 -1   -> 0
   1 0, 1 -> 0
   2 0    -> 2
   3 0, 3 -> 2
   4 0    -> 4
   5 0    -> 4

*/

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
      int answer = 0;
      stack<int> st;
      st.push(-1);

      for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push(i);
        else {
          st.pop();
          if (st.empty()) st.push(i);
          else {
            answer = max(answer, i - st.top());
          }
        }
        cout << i << ", " << answer << endl;
      }

      return answer;
    }
};

int main() {
  Solution s;
  cout << s.longestValidParentheses(")()())") << endl;
  return 0;
}