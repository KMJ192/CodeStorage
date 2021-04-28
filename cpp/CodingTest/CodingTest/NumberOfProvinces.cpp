#include<iostream>
#include<vector>

using namespace std;

#define MAX_SIZE 200
//1. 1번원소에서 연결되어있는 모든 간선 DFS탐색
//2. 탐색이 되지 않은 가장 작은 원소부터 연결되어 있는 모든 원소 탐색
//3.

class Solution {
    bool visited[MAX_SIZE] = { false, };
    int next = 0;
    
public:
    void dfs(vector<vector<int>>& isConnected, int cell) {
       // cout << "현재 : " << cell + 1<< endl;
        
        bool toggle = false;
        for (int i = cell; i < isConnected.size(); i++) {
            if (visited[i] == true) {
                continue;
            }
            visited[i] = true;
            for (int j = i + 1; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] == 1) {
                    cout << "현재 도 " << i + 1 << "와 " << j + 1 << " 연결\n";
                    dfs(isConnected, j);
                    toggle = true;
                    break;
                }
            }
            if (toggle == true) toggle = false;
            else next++;
        }
        cout << next << endl;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int answer = 0;
        dfs(isConnected, 0);
        
        return answer;
    }
};

int main() {
    //vector<vector<int>> isConnected = {
    //    //{1, 1, 0},
    //    //{1, 1, 0},
    //    //{0, 0, 1}
    //    {1, 0, 0},
    //    {0, 1, 0},
    //    {0, 0, 1}
    //};

    //총 15개
    //
    vector<vector<int>> isConnected = {
        {1,1,0,0,0,0,0,0,0,0,0,0,0,0,{1,1,0,0,0,0,0,1,0,0,0,0,0,0,0},0},
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
    s.findCircleNum(isConnected);

	return 0;
}