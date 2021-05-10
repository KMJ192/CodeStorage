#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<map>

using namespace std;

class Solution {
private:
    map<char, int> q;
    map<char, int> m;
    list<char> priority_char;
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        sort(tasks.begin(), tasks.end());
        int total = tasks.size();
        char tmp = ' ';
        for (char c : tasks) {
            m[c]++;
            q[c] = 0;
            if (c != tmp) {
                priority_char.push_back(c);
            }
            tmp = c;
        }

        int time = 0;
        vector<char> test;
        while (total) {
            tmp = ' ';
            time++;
            vector<char> object;
            for (auto it = m.begin(); it != m.end(); it++) {
                //�۾��ؾߵ� ���� �����鼭, ��Ÿ���� 0�̸鼭, �۾����� ���� ������ ��, �켱������ �ʿ���
                if (it->second > 0 && q[it->first] == 0) {
                    //�켱 ������ ����ϱ� ���� ��� task�� �迭�� push �س��´�.
                    cout << it->first << it->second << endl;
                    //object.push_back(it->first);
                    if (priority_char.front() == it->first) {
                        char sft = priority_char.front();
                        cout << sft << endl;
                        //��Ÿ�� �ۼ�
                        q[sft] = n;
                        //�۾��׽�ũ ����
                        m[sft]--;
                        priority_char.pop_front();
                        if (m[sft] > 0) {
                            priority_char.push_back(sft);
                        }
                        tmp = sft;
                        total--;
                        break;
                    }
                }
            }
            test.push_back(tmp);
            for (auto it = q.begin(); it != q.end(); it++) {
                if (q[it->first] > 0 && tmp != it->first) {
                    it->second--;
                }
            }
        }
        for (int i = 0; i < test.size(); i++) {
            cout << test[i];
        }

        return time;
    }
};

int main() {

    vector<char> tasks = { 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
    //vector<char> tasks = { 'A', 'A', 'A', 'B', 'B', 'B', 'C' };
    //vector<char> tasks = { 'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'E' };

    Solution s;
    cout << s.leastInterval(tasks, 2);

    return 0;
}
