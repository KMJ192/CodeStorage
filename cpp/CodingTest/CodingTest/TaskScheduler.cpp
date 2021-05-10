#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

//class Solution {
//private:
//    map<char, int> coolTime;
//    map<char, int> task;
//public:
//    int leastInterval(vector<char>& tasks, int n) {
//        if (n == 0) return tasks.size();
//        sort(tasks.begin(), tasks.end());
//        int total = tasks.size();
//        for (char& c : tasks) {
//            task[c]++;
//            coolTime[c] = 0;
//        }
//
//        int time = 0;
//        while (total) {
//            char tmp = ' ';
//            time++;
//            bool next = false;
//            priority_queue<pair<int, char>> pq;
//            for (auto it = task.begin(); it != task.end(); it++) {
//                //�۾��ؾߵ� ���� �����鼭, ��Ÿ���� 0�� ��, �켱������ �ʿ���
//                if (it->second > 0 && coolTime[it->first] == 0) {
//                    //�켱 ������ ����ϱ� ���� ��� task�� �迭�� push �س��´�.
//                    //�켱���� 
//                    //1. �۾��ؾߵ� ���� ���� ���� ��
//                    //2. �۾� ������ ���� ���� �Ȱ�
//                    pq.push(pair<int, char>(it->second, it->first));
//                    next = true;
//                }
//            }
//            if (next == true) {
//                char sht = pq.top().second;
//                coolTime[sht] = n;
//                task[sht]--;
//                tmp = sht;
//                total--;
//            }
//
//            //test.push_back(tmp);
//            for (auto it = coolTime.begin(); it != coolTime.end(); it++) {
//                if (coolTime[it->first] > 0 && tmp != it->first) {
//                    it->second--;
//                }
//            }
//        }
//        return time;
//    }
//};

class Solution {
private:
    map<char, int> task;
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        //tasks�� ���� ���� task�� ���� ���� idle�� ���� �� �ִ�.
        //���� ���� ���� task�� idle ���� ���� ���� ���� task���� idle�� ä�� �ִ´�.
        int maxTask = 0, m = tasks.size();
        int numpeak = 0;

        //���� ���ڰ� ���� task�� ���� ���� �����Ѵ�.
        for (auto& c : tasks) {
            maxTask = max(maxTask, ++task[c]);
        }

        //���� ���ڰ� ���� task�� ���� ���Ѵ�.
        for (auto& c : task) {
            if (c.second == maxTask) {
                numpeak++;
            }
        }
        //(���� ���ڰ� ���� task�� �� - 1) * (cool time + 1) + ���� ���ڰ� ���� task�� ��
        return max(m,(maxTask - 1) * (n + 1) + numpeak);
    }
};

int main() {

    //vector<char> tasks = { 'A', 'B', 'C' };
    //vector<char> tasks = { 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
    vector<char> tasks = { 'A', 'A', 'A', 'B', 'B', 'B' };
    //vector<char> tasks = { 'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'E' };

    Solution s;
    cout << s.leastInterval(tasks, 2);

    return 0;
}
