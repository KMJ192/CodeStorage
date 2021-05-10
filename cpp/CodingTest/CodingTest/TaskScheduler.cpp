#include<iostream>
#include<vector>
#include<algorithm>
<<<<<<< Updated upstream
#include<map>
=======
#include<unordered_map>
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
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
=======
    priority_queue<char> q;                  //�۾� queue
    unordered_map<char, int> coolDown;   //pop �� coolDown Time
    unordered_map<char, int> m;          //tasks�� ���� �� ����
public:
    int leastInterval(vector<char>& tasks, int n) {
        for (int i = 0; i < tasks.size(); i++) {
            m[tasks[i]]++;
        }
        /*for (auto it = m.begin(); it != m.end(); it++) {
            cout << it->first << ", " << it->second << endl;
        }*/
        int time = 1;
        int index = 1;

        q.push(tasks[0]);
        coolDown[tasks[0]] = n;
        m[tasks[0]]--;

        while (!q.empty()) {
            time++;
            bool nextStep = false, coolTime = false;
            char task = q.top();
            cout << "������ task : " << task << endl;
            if (coolDown.size() > 0) {
                cout << "��Ÿ�� ��Ȳ" << endl;
                for (auto it = coolDown.begin(); it != coolDown.end(); it++) {
                    cout << it->first << ", " << it->second << endl;
                }
            }
            q.pop();
            if (task != ' ') {
                for (auto it = m.begin(); it != m.end(); it++) {
                    //�����ؾ� �Ǵ� task�� ���� �ִ��� Ȯ��
                    cout << it->first << ", " << it->second << endl;
                    if (it->second > 0) {
                        nextStep = true;
                        //�ִٸ� ��Ž Ȯ��
                        for (int i = 0; i < coolDown.size(); i++) {
                            /*if (it->first == coolDown[i].first && coolDown[i].second > 0) {
                                coolTime = true;
                                break;
                            }*/
                        }
                        //��Ž ���°� �ִٸ� q�� push�� m���� 1 ����
                        if (coolTime == false) {
                            q.push(it->first);
                            //coolDown.push_back(pair<char, int>(it->first, n));
                            m[it->first]--;
                            break;
                        }
                        else {
                            coolTime = false;
                        }
                    }
                }
            }
            if (nextStep == true && q.empty()) {
                q.push(' ');
            }
            //��Ÿ�� ����
            //for (int i = 0; i < coolDown.size() - 1; i++) {
            //    if (coolDown[i].second > 0) {
            //        coolDown[i].second--;
            //    }
            //}
        }
        return time;
>>>>>>> Stashed changes
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
