#include<iostream>
#include<vector>

using namespace std;

class Solution {    
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;
        for (int i = 0; i < isConnected[node].size(); i++) {
            if (isConnected[node][i] == 1 && visited[i] == 0) {
                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        //노드별로 방문여부를 저장하는 vector 초기화
        vector<int> visited(isConnected.size(), 0);        
        int answer = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (visited[i] == 0) {
                dfs(i, isConnected, visited);
                answer++;
            }
        }
        return answer;
    }
};

int main() {
    //vector<vector<int>> isConnected = {
    //    {1, 0, 0},
    //    {0, 1, 0},
    //    {0, 0, 1}
    //};
    //[[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]
    vector<vector<int>> isConnected = {
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
        {0,1,0,1,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,0,1,0,0,0,1,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},
        {0,1,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}
    };
    
    Solution s;
    
    cout << s.findCircleNum(isConnected);

	return 0;
}