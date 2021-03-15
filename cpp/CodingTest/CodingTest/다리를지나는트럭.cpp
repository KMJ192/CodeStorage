#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0, total_weight = 0, entered = 0, cCount = 0;
    bool swi = false;
    queue<pair<int, int>> info;

    while (1) {
        if (swi == true) {
            swi = false;
        }
        else {
            time++;
        }
        if (time != 1) {
            if (time == info.front().second) {
                info.pop();
                total_weight -= truck_weights[cCount];
                cCount++;
            }
        }

        if (truck_weights.size() > entered) {
            if ((total_weight + truck_weights[entered]) > weight) {
                time = info.front().second;
                swi = true;
                continue;
            }
            info.push(make_pair(time, time + bridge_length));
            total_weight += truck_weights[entered];
            entered++;
        }

        if (info.empty()) {
            break;
        }
    }

    return time;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //vector<int> truck_weight = { 10,10,10,10,10,10,10,10,10,10 };
    vector<int> truck_weight = { 7, 4, 5, 6 };
    //vector<int> truck_weight = { 10 };
    cout << solution(2, 10, truck_weight);

    return 0;
}