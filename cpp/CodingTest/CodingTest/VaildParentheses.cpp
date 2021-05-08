#include<iostream>
#include<stack>

using namespace std;

class Solution {
private:
    stack<char> st;
public:
    Solution(){}
    ~Solution() {
        for (int i = 0; i < st.size(); i++) st.pop();
    }
    bool isValid(string s) {
        if (s[0] == ')' || s[0] == ']' || s[0] == '}') {
            return false;
        }
        else if (s[s.size() - 1] == '(' || s[s.size() - 1] == '[' || s[s.size() - 1] == '{') {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
                continue;
            }
            if (st.empty()) {
                if (s[i] == ')' || s[i] == '}' || s[i] == ']') return false;
            }
            if (s[i] == ')' && !st.empty() && st.top() != '(') {
                return false;
            }
            if (s[i] == '}' && !st.empty() && st.top() != '{') {
                return false;
            }
            if (s[i] == ']' && !st.empty() && st.top() != '[') {
                return false;
            }
            if(!st.empty()) st.pop();
        }
        if (!st.empty()) return false;

        return true;
    }
};

int main() {
    Solution s;
    cout << s.isValid("()");
	return 0;
}