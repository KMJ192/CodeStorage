#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

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
void Permutation(string object, vector<int> position, int count) {
    count++;
    if (position.size() >= object.size()) return; //노드가 배열보다 크면 안된다.
    cout << object.size() << endl;
    //여기서 position 배열을 잘만들어야됨
    //#######################################
    for (int i = 0; i < position.size(); i++) {
        cout << position[i];
    }
    cout << endl;
    //#######################################

    temp.push_back(position);
    position.back() = position.back() + 1;

    //탐색중인 원소 중 가장 마지막 원소가 탐색해야 될 문자열의 마지막을 넘긴 경우
    if (position.back() > (object.size() - 1)) {
        return;
        /*position[position.size() - 2] = position[position.size() - 2] + 1;
        position.back() = position[position.size() - 2] + 1;*/
    }
    
    //탐색중인 원소 중 가장 첫번째의 원소와 마지막 원소 사이 공간이 없을 경우까지 탐색
    while (position[0] <= (object.size() - position.size())) {
        Permutation(object, position, count);
    }
    cout << count << "번째 함수 완료!" << endl;
}

string solution(string number, int k) {
    vector<int> tmp;
    for (int i = 0; i < k; i++) {
        tmp.push_back(i);
    }
    Permutation(number, tmp, 0);
    
    string answer = "";
    return answer;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution("1231234", 3);

    return 0;
}