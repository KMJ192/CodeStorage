#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//Input: 
//  2���� �迭 grid�� ���� ���
//  [2, 1, 1],
//  [1, 1, 0],
//  [0, 1, 1]
//Output: 4
//Constraints :
// 1) m�� grid.length�̰�, n�� grid[i].length�� ���
//     1 <=m, n <= 10
// 2) grid[i][j]�� 0, 1, 2�� ���� ���´�,
//Edge Case :
//brute force : naive
//  BFSǮ��
//  time : O(3n^2)
//  space : O(n^2)
//code
class Solution {
private:
    queue<pair<int, int>> q;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int min = 0;
        cout << "���� ����" << endl;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                cout << grid[i][j] << " ";
                if (grid[i][j] == 2) {
                    q.push(pair<int, int>(i, j));
                }
            }
            cout << endl;
        }
        cout << endl;
        while (!q.empty()) {
            cout << "Ȯ��" << min+1 << "��°" << endl;
            int loop = q.size();
            for (int i = 0; i < loop; i++){
                //cout << q.front().first << q.front().second << endl;
                //vector�� �����ϴ� �Լ� call
                grid = change(grid, pair<int, int>(q.front().first, q.front().second));
                //cout << q.front().first << ", " << q.front().second << endl;
                q.pop();
            }
            for (int n = 0; n < grid.size(); n++) {
                for (int m = 0; m < grid[n].size(); m++) {
                    cout << grid[n][m] << " ";
                }
                cout << endl;
            }
            cout << endl;
            min++;
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        if (min != 0) min--;
        return min;
    }
    vector<vector<int>> change(vector<vector<int>>& grid, pair<int, int> pos) {
        //4�������� �ش� ���� 1�̸� 2�� �� ����
        //��
        if (pos.first > 0) {
            if (grid[pos.first - 1][pos.second] == 1) {
                grid[pos.first - 1][pos.second] = 2;
                q.push(pair<int, int>(pos.first - 1, pos.second));
            }
        }
        //��
        if (pos.first < grid.size() - 1) {
            if (grid[pos.first + 1][pos.second] == 1) {
                grid[pos.first + 1][pos.second] = 2;
                q.push(pair<int, int>(pos.first + 1, pos.second));
            }
        }
        //��
        if (pos.second > 0) {
            if (grid[pos.first][pos.second - 1] == 1) {
                grid[pos.first][pos.second - 1] = 2;
                q.push(pair<int, int>(pos.first, pos.second - 1));
            }
        }
        //��
        if (pos.second < grid[pos.first].size() - 1) {
            if (grid[pos.first][pos.second + 1] == 1) {
                grid[pos.first][pos.second + 1] = 2;
                q.push(pair<int, int>(pos.first, pos.second + 1));
            }
        }
        return grid;
    }
};

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution s;
    cout << s.orangesRotting(grid);

	return 0;
}