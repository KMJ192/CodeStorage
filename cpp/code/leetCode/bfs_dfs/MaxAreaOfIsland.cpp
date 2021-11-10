#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    int cnt = 0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int answer = 0;
        for (int y = 0; y < (int)grid.size(); y++) {
            for (int x = 0; x < (int)grid[y].size(); x++) {
                if (grid[y][x] == 1) {
                    recursion(grid, x, y);
                    answer = max(answer, cnt);
                    cnt = 0;
                }
            }
        }
        return answer;
    }

    void recursion(vector<vector<int>>& grid, int x, int y) {
        if (
            y < 0 ||
            y >(int)grid.size() - 1 ||
            x < 0 ||
            x >(int)grid[y].size() - 1
            ) return;
        if (grid[y][x] == 1) {
            grid[y][x] = 0;
            cnt++;
            recursion(grid, x + 1, y);
            recursion(grid, x, y + 1);
            recursion(grid, x - 1, y);
            recursion(grid, x, y - 1);
        }
    }
};

int main() {
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    Solution s;
    cout << s.maxAreaOfIsland(grid);

    return 0;
}