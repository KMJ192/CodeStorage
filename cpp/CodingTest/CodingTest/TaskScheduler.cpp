#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
private:
    queue<char> q;

    vector<pair<char, int>> v;
public:
    int leastInterval(vector<char>& tasks, int n) {
        sort(tasks.begin(), tasks.end());
        char tmp = ' ';
        int index = -1;
        for (int i = 0; i < tasks.size(); i++) {
            if (tmp != tasks[i]) {
                index++;
                v.push_back(pair<char, int>(tasks[i], 1));
            }
            else {
                v[index].second++;
            }
            tmp = tasks[i];
        }
        for (int i = 0; i < v.size(); i++) {
            cout << v[i].first << ", " << v[i].second << endl;
        }
        index = 0;
        for (int i = 0; i < tasks.size(); i++) {
            q.push(v[0].first);
            v[1].second -= 1;

        }
        return 0;
    }
};

int main() {

    vector<char> tasks = { 'A', 'A', 'A', 'B', 'B', 'B' };
    //vector<char> tasks = { 'A', 'A', 'A', 'B', 'B', 'B', 'C' };

    Solution s;
    s.leastInterval(tasks, 2);

    return 0;
}
