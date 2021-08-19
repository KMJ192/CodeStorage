#include<iostream>
#include<set>
#include<vector>

using namespace std;

vector<vector<int>> outbound = { { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };

void recursion(vector<vector<int>>& arr, int x, int y, int i, int j, vector<pair<int, int>>& v) {
    if (i < 0 || i >= arr.size() || j < 0 || j >= arr[0].size() || arr[i][j] <= 0) return;

    arr[i][j] *= -1;

    v.push_back({ i - x, j - y });

    for (auto o : outbound) {
        recursion(arr, x, y, i + o[0], j + o[1], v);
    }
}

int distinctIslands(vector<vector<int> >& arr) {
    // edge case
    if (arr.size() == 0 || arr[0].size() == 0) return 0;

    set<vector<pair<int, int>>> path;

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            if (arr[i][j] != 1) continue;

            vector<pair<int, int>> v;

            recursion(arr, i, j, i, j, v);

            path.insert(v);
        }
    }

    return path.size();
}

int main() {
    vector<vector<int> > arr = {
        { 1, 1, 0, 0, 0 },
        { 1, 1, 0, 0, 0 },
        { 0, 0, 0, 1, 1 },
        { 0, 0, 0, 1, 1 }
    };

    cout << distinctIslands(arr);

    return 0;
}