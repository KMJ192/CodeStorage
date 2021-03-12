#include<iostream>
#include <queue>
#include <vector>

using namespace std;

//ť�� ����ϴ� �������� ����
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge; //�ٸ� ����
    int inputed = 0; //�Էµ� ������ ���� ����
    int count = 0; //�ð��� ����
    int iter = 0; //������ index�� ����

    while (1) {
        //�ٸ� ���̺��� queue�� ���̰� ������� ��� POP
        if (bridge.size() > bridge_length) {
            inputed -= bridge.front();
            bridge.pop();
        }
        //loop Ż�� ����
        if (iter >= truck_weights.size() && inputed == 0) {
            break;
        }
        //���� > �Էµ� ������ ������ �������ߺ��� Ŭ��� 0�� push/�ƴҰ�� �迭�� ���Ҹ� push
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