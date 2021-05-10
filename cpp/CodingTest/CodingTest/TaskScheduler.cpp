#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<map>
#include<queue>

using namespace std;

class Solution {
private:
    map<char, int> q;
    map<char, int> m;
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        sort(tasks.begin(), tasks.end());
        int total = tasks.size();
        for (char c : tasks) {
            m[c]++;
            q[c] = 0;
        }

        int time = 0;
        while (total) {
            char tmp = ' ';
            time++;
            bool next = false;
            priority_queue<pair<int, char>> pq;
            for (auto it = m.begin(); it != m.end(); it++) {
                //작업해야될 것이 있으면서, 쿨타임이 0인 것, 우선순위가 필요함
                if (it->second > 0 && q[it->first] == 0) {
                    //우선 순위를 계산하기 위해 대상 task를 배열에 push 해놓는다.
                    //우선순위 
                    //1. 작업해야될 것이 가장 많은 것
                    //2. 작업 안한지 가장 오래 된것
                    pq.push(pair<int, char>(it->second, it->first));
                    next = true;
                }
            }
            if (next == true) {
                char sht = pq.top().second;
                q[sht] = n;
                m[sht]--;
                tmp = sht;
                total--;
            }

            //test.push_back(tmp);
            for (auto it = q.begin(); it != q.end(); it++) {
                if (q[it->first] > 0 && tmp != it->first) {
                    it->second--;
                }
            }
        }

        return time;
    }
};

int main() {

    //vector<char> tasks = { 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
    //vector<char> tasks = { 'A', 'A', 'A', 'B', 'B', 'B', 'C' };
    vector<char> tasks = { 'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'E' };

    Solution s;
    cout << s.leastInterval(tasks, 2);

    return 0;
}
