#include<iostream>
#include <queue>
#include <vector>

using namespace std;

//큐를 사용하는 과정으로 수정
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge; //다리 생성
    int inputed = 0; //입력된 원소의 합을 저장
    int count = 0; //시간을 저장
    int iter = 0; //원소의 index를 저장

    while (1) {
        //다리 길이보다 queue의 길이가 길어졌을 경우 POP
        if (bridge.size() > bridge_length) {
            inputed -= bridge.front();
            bridge.pop();
        }
        //loop 탈출 조건
        if (iter >= truck_weights.size() && inputed == 0) {
            break;
        }
        //조건 > 입력된 원소의 총합이 적재하중보다 클경우 0을 push/아닐경우 배열의 원소를 push
        count++;
        inputed += truck_weights[iter];
        if (inputed > weight) {
            bridge.push(0);
            inputed -= truck_weights[iter];
        }
        else {
            if (iter < truck_weights.size()) {
                bridge.push(truck_weights[iter]);
                iter++;
            }
            else {
                bridge.push(0);
            }
        }
    }

    return count;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> truck_weight = { 7,4,5,6 };
    //vector<int> truck_weight = { 10 };
    //vector<int> truck_weight = { 10,10,10,10,10,10,10,10,10,10 };
    cout << solution(2, 10, truck_weight);
    //cout << solution(100, 100, truck_weight);

    return 0;
}