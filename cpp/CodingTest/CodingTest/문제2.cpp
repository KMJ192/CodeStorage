#include<iostream>
#include <map>
#include <string>

using namespace std;

bool check(string s) {
    //ó���� �ݴ°�ȣ�̰ų� �������� ���� ��ȣ�ϰ�� false return
    if (s[0] == ')' || s[0] == ']' || s[0] == '}') {
        return false;
    }
    else if(s[s.size() - 1] == '(' || s[s.size() - 1] == '[' || s[s.size() - 1] == '{') {
        return false;
    }

    map<char, int> m;
    for (int i = 0; i < s.size(); i++) {
        //���ڿ� ��ȸ
        if (m.find(s[i]) != m.end()) {
            //map�� �����鼭, �ݴ� ��ȣ�� ����̸鼭, ���� ��ȣ�� ������ ���
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
            //map�� �����鼭, �ݴ� ��ȣ�� ����̸鼭, ���� ��ȣ�� ������ ���
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
        //map�� ������� ������ �ȴ�, ���� -> ()[]{}
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