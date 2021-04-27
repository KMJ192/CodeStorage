#include<iostream>
#include<vector>

using namespace std;


//1. 1번원소에서 연결되어있는 모든 간선 DFS탐색
//2. 탐색이 되지 않은 가장 작은 원소부터 연결되어 있는 모든 원소 탐색
//3.

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //배열의 길이 = 도의 수
        int answer = isConnected.size();
        for (int i = 0; i < isConnected.size(); i++) {
            for(int j = i; j <isConnected[i].size(); j++){
                /*if (j == i) {
                    continue;
                }*/
                cout << isConnected[i][j] << " ";
                if (isConnected[i][j] == 1) answer--;
            }
            cout << "\n";
        }
        if (answer <= 0) return 1;
        return answer;
    }
};

int main() {
    //vector<vector<int>> isConnected = {
    //    {1, 1, 0},
    //    {1, 1, 0},
    //    {0, 0, 1}
    //    /*{1, 0, 0},
    //    {0, 1, 0},
    //    {0, 0, 1}*/
    //};

    //총 15개
    //
    vector<vector<int>> isConnected = {
        {1,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,1,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,1,1,0,0,0,0},
        {0,0,0,1,0,1,0,0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,1,0,1,0,0,0,0,1,0},
        {1,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,1,1,0,0,0,0,1,0},
        {0,0,0,0,1,0,0,0,0,1,0,1,0,0,1},
        {0,0,0,0,1,1,0,0,0,0,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,1,0,1,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,1}
    };
    Solution s;
    cout << s.findCircleNum(isConnected);

	return 0;
}