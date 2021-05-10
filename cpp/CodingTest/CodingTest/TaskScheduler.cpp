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
                //�۾��ؾߵ� ���� �����鼭, ��Ÿ���� 0�� ��, �켱������ �ʿ���
                if (it->second > 0 && q[it->first] == 0) {
                    //�켱 ������ ����ϱ� ���� ��� task�� �迭�� push �س��´�.
                    //�켱���� 
                    //1. �۾��ؾߵ� ���� ���� ���� ��
                    //2. �۾� ������ ���� ���� �Ȱ�
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
