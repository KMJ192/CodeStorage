#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include <stack>

using namespace std;

//���� ���� ���� �����ϴ� ���α׷��� �������.
// k�� Ȱ��ȭ �� ���� row�� ����Ų��.
// U n�� ���� n�� �̵��ϴ� ���̴�.
// D n�� �Ʒ��� n�� �̵��ϴ� ���̴�.
// C�� �ش� ���� �����ϴ� ���̴�.
// Z�� �ֱ� ������ ���� ������� �����մϴ�.
// ����, ���� �� Ȱ��ȭ�� ������ �ʴ´�.
//������ ���� X, ���� ���� �״�θ� O�� return�Ѵ�

string rmCmd(string object, int position) {
    if (object.size() <= position) return object;
    unsigned int pos = position;
    if (pos == 0)  return object.substr(pos + 1, object.size());

    return object.substr(0, pos) + object.substr(pos + 1, object.size());
}

string solution(int n, int k, vector<string> cmd) {
    string tmp;
    for (int i = 1; i <= n; i++) {
        tmp = tmp + to_string(i);
    }
    
    stack<int> st;
    for(int i = 0; i < cmd.size(); i++) {
        int r = 0;
        if (cmd[i][0] == 'D') {
            r = cmd[i][2] - '0';
            k += r;
        }
        if (cmd[i][0] == 'U') {
            r = cmd[i][2] - '0';
            k -= r;
        }
        if (cmd[i][0] == 'C') {
            st.push(tmp[k] - '0');
            tmp = rmCmd(tmp, k);

        }
        if (cmd[i][0] == 'Z') {
            if (!st.empty()) {
                tmp += to_string(st.top());
                st.pop();
            }
        }
    }
    string answer = "";
    sort(tmp.begin(), tmp.end());

    int index = 0;
    for (int i = 0; i < n; i++) {
        if (tmp[index] - '0' == i + 1) {
            index++;
            answer += "O";
        }
        else {
            answer += "X";
        }
        
    }

    cout << answer << endl;
    
    return answer;
}

int main() {
    vector<string> s = {
        "D 2",
        "C",
        "U 3",
        "C",
        "D 4",
        "C",
        "U 2",
        "Z",
        "Z",
        "U 1",
        "C"
    };
    solution(8, 2, s);
    return 0;
}