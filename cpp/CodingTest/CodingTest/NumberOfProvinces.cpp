#include<iostream>
#include<vector>

using namespace std;

#define MAX_SIZE 200
//1. 1�����ҿ��� ����Ǿ��ִ� ��� ���� DFSŽ��
//2. Ž���� ���� ���� ���� ���� ���Һ��� ����Ǿ� �ִ� ��� ���� Ž��
//3.

class Solution {
    bool visited[MAX_SIZE] = { false, };
    int next = 0;
    
public:
    void dfs(vector<vector<int>>& isConnected, int cell) {
       // cout << "���� : " << cell + 1<< endl;
        
        bool toggle = false;
        for (int i = cell; i < isConnected.size(); i++) {
            if (visited[i] == true) {
                continue;
            }
            visited[i] = true;
            for (int j = i + 1; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] == 1) {
                    cout << "���� �� " << i + 1 << "�� " << j + 1 << " ����\n";
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

    //�� 15��
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