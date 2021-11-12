#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int obj;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        obj = image[sr][sc];
        vector<vector<int>> visitied(image.size(), vector<int>(image[0].size(), 0));

        recursion(image, sr, sc, newColor, visitied);

        return image;
    }

    void recursion(vector<vector<int>>& image, int y, int x, int newColor, vector<vector<int>>& visitied) {
        cout << y << x << "\n";
        if (x < 0 || y < 0 || x > image[0].size() - 1 || y > image.size() - 1 || visitied[y][x] == 1) return;
        visitied[y][x] = 1;
        if (image[y][x] == obj) {
            image[y][x] = newColor;
            recursion(image, y, x + 1, newColor, visitied);
            recursion(image, y, x - 1, newColor, visitied);
            recursion(image, y + 1, x, newColor, visitied);
            recursion(image, y - 1, x, newColor, visitied);
        }
    }
};

int main() {
    vector<vector<int>> image = {
        {0, 0, 0},
        {0, 1, 0},
    };

    Solution s;
    vector<vector<int>> v = s.floodFill(image, 0, 0, 2);
    cout << "\n";
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}