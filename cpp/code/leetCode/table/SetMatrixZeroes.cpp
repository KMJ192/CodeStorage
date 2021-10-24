#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    using position = pair<int, int>;
    vector<position> positions;
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for (int y = 0; y < matrix.size(); y++) {
            for (int x = 0; x < matrix[y].size(); x++) {
                if (matrix[y][x] == 0) {
                    positions.push_back({ x, y });
                }
            }
        }
        for (int i = 0; i < positions.size(); i++) {
            xPosition(matrix, positions[i].first, positions[i].second);
            yPosition(matrix, positions[i].first, positions[i].second);
        }
    }
    void yPosition(vector<vector<int>>& matrix, int x, int y) {
        int p = y;
        while (p) {
            p--;
            matrix[p][x] = 0;
        }
        p = y;
        while (p < matrix.size() - 1) {
            p++;
            matrix[p][x] = 0;
        }

    }

    void xPosition(vector<vector<int>>& matrix, int x, int y) {
        int p = x;
        while (p) {
            p--;
            matrix[y][p] = 0;
        }
        p = x;
        while (p < matrix[y].size() - 1) {
            p++;
            matrix[y][p] = 0;
        }
    }
};