#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> tmp;
    vector<int> answer;
    int data;
    for (int i = 0; i < commands.size(); i++) {
        for (int j = commands[i][0] - 1; j <= commands[i][1] - 1; j++) {
            //tmp.push_back(array[j]);
            //cout << array[j];
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(), tmp.end());
        data = commands[i][2] - 1;
        answer.push_back(tmp[data]);
        tmp.clear();
    }

    return answer;
}

int main() {

    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands = {
        {2, 5, 3},
        {4, 4, 1},
        {1, 7, 3}
    };
    solution(array, commands);

    return 0;
}