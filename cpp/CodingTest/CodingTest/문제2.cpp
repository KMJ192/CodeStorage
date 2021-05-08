#include<iostream>
#include <map>
#include <string>

using namespace std;

bool check(string s) {
    //처음이 닫는괄호이거나 마지막이 여는 괄호일경우 false return
    if (s[0] == ')' || s[0] == ']' || s[0] == '}') {
        return false;
    }
    else if(s[s.size() - 1] == '(' || s[s.size() - 1] == '[' || s[s.size() - 1] == '{') {
        return false;
    }

    map<char, int> m;
    for (int i = 0; i < s.size(); i++) {
        //문자열 순회
        if (m.find(s[i]) != m.end()) {
            //map에 있으면서, 닫는 괄호일 경우이면서, 여는 괄호가 없었던 경우
            if (s[i] == ']') {
                if (m.find('[') == m.end()) {
                    return false;
                }
                else {
                    if (m.find('[')->second <= m.find(']')->second + 1) return false;
                }
            }
            else if (s[i] == '}') {
                if (m.find('{') == m.end()) {
                    return false;
                }
                else {
                    if (m.find('{')->second <= m.find('}')->second + 1) return false;
                }
            }
            else if (s[i] == ')') {
                if (m.find('(') == m.end()) {
                    return false;
                }
                else {
                    if (m.find('(')->second <= m.find(')')->second + 1) return false;
                }
            }
            m.find(s[i])->second += 1;
        }
        else {
            //map에 없으면서, 닫는 괄호일 경우이면서, 여는 괄호가 없었을 경우
            if (s[i] == ']') {
                if (m.find('[') == m.end()) {
                    return false;
                }
            }
            else if (s[i] == '}') {
                if (m.find('{') == m.end()) {
                    return false;
                }
            }
            else if (s[i] == ')') {
                if (m.find('(') == m.end()) {
                    return false;
                }
            }
            m.insert(pair<char, int>(s[i], 1));
        }
    }
    cout << s << endl;
    int cnt = 0;
    int tmp = 0;
    for (map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
        //map은 순서대로 정렬이 된다, 순서 -> ()[]{}
        cnt++;
        if (cnt % 2 == 0) {             //0, 2, 4
            if (tmp != it->second) {
                return false;
            }
        }
        else {                              //1, 3, 5
            tmp = it->second;
        }
    }
    return true;
}

string leftShift(string s) {
    return s.substr(1, s.size()) + s.substr(0, 1);
}

string rigthShift(string s) {
    return s.substr(s.size() - 1, s.size()) + s.substr(0, s.size() - 1);
}

int solution(string s) {
    int answer = 0;
    string tmp = s;
    for (int i = 0; i < s.size(); i++) {
        //if (check(tmp) == true) {
        //    answer++;
        //}
        cout << tmp << endl;
        tmp = leftShift(tmp);
    }
    cout << endl;
    tmp = s;
    for (int i = 0; i < s.size(); i++) {
        cout << tmp << endl;
        tmp = rigthShift(tmp);
    }
    return answer;
}

int main() {
    string s = "[](){}";
    cout << solution(s);
    //map<string, string> t;

    return 0;
}