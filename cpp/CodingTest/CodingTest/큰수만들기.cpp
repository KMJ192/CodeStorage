#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

priority_queue<string> total;
vector<vector<int>> temp;

//대상 문자열, 대상 문자열에서 잘라내야되는 위치값이 담겨져있는 배열
string ExtractString(string object, vector<int> position) {
    if (object.size() < position.size()) return "";
    int cnt = 0;
    string tmp;

    for (int n = 0; n < object.size(); n++) {
        if (cnt < position.size()) {
            if (n == position[cnt]) {
                cnt++;
                continue;
            }
        }
        tmp = tmp + object[n];
    }
    return tmp;
}

//대상 문자열(배열),  배열에서 현재 방문할 위치값을 담은 배열
//배열의 길이 == 1Cycle별 대상 문자열에서 방문할 원소의 갯수
//첫번째를 바라보는 원소의 위치가 마지막의 위치까지 오면 재귀함수 종료시키기
vector<int> finalPos;
vector<int> position;
void Permutation(string object, vector<int> pos) { 

    temp.push_back(pos);
    pos.back() = pos.back() + 1;
    if (pos.back() > (object.size() - 1)) {
        position = pos;
        position.back() = position.back() - 1;
        return;
    }
    Permutation(object, pos);
}

string solution(string number, int k) {
    int count = 0, it;
    for (int i = 0; i < k; i++) {
        position.push_back(i);
        finalPos.push_back(number.size() - k + i);
    }
    while (position[0] <= (number.size() - position.size())) {
        Permutation(number, position);
        for (int i = position.size() - 1; i >= 0; i--) {
            if (position[i] != finalPos[i]) {
                count = i;
                break;
            }
        }
        it = 0;
        for (int i = count; i < position.size(); i++) {
            if (i == count) {
                position[i] = position[i] + 1;
            }
            else {
                it++;
                position[i] = position[count] + it;
            }
        }
    }
    for (int i = 0; i < temp.size(); i++) {
        total.push(ExtractString(number, temp[i]));
    }
    
    string answer = total.top();
    return answer;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //string test = "1234";
    //cout << stoi(test.substr(0, 2));

    cout << solution("1231234", 3);

    return 0;
}