#include<iostream>
#include<vector>

using namespace std;


//1. 1�����ҿ��� ����Ǿ��ִ� ��� ���� DFSŽ��
//2. Ž���� ���� ���� ���� ���� ���Һ��� ����Ǿ� �ִ� ��� ���� Ž��
//3.

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //�迭�� ���� = ���� ��
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

    //�� 15��
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