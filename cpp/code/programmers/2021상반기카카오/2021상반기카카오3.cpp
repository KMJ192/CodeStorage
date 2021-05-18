#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include <stack>

using namespace std;

//행을 선택 삭제 복구하는 프로그램을 만들었다.
// k는 활성화 된 현재 row를 가리킨다.
// U n은 위로 n번 이동하는 것이다.
// D n은 아래로 n번 이동하는 것이다.
// C는 해당 행을 삭제하는 것이다.
// Z는 최근 삭제한 행을 원래대로 복구합니다.
// 삭제, 복구 시 활성화는 변하지 않는다.
//삭제된 것은 X, 원래 상태 그대로면 O를 return한다

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