#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
  int check(string s) {
    stack<char> st;
    for(char c: s) {
      if (c == '(') st.push(c);
      else if (c==')' && st.size() > 0 && st.top() == '(') st.pop();
      else if (c == ')') st.push(c);
    }

    return st.size();
  }
public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> answer;
    int sLen = s.length();
    int w = check(s);

    queue<string> q;
    unordered_set<string> dictionary;
    q.push(s);

    while (!q.empty()) {
      string f = q.front();
      q.pop();

      if (dictionary.find(f) == dictionary.end()) {
        dictionary.insert(f);
      } else {        
        continue;
      }

      if (check(f) == 0) {
        answer.push_back(f);
        continue;
      }
      
      for (int i = 0; i < f.length(); i++) {
        string curStr = f.substr(0, i) + f.substr(i + 1);
        if (curStr.length() >= sLen - w) {
          q.push(curStr);
        }
      }
    }
    
    return answer;
  }
};

int main() {

  string s = "(a)())()";

  Solution a;
  vector<string> v = a.removeInvalidParentheses(s);
  for (string d: v) {
    cout << d << endl;
  }

  return 0;
}