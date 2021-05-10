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
//                //작업해야될 것이 있으면서, 쿨타임이 0인 것, 우선순위가 필요함
//                if (it->second > 0 && coolTime[it->first] == 0) {
//                    //우선 순위를 계산하기 위해 대상 task를 배열에 push 해놓는다.
//                    //우선순위 
//                    //1. 작업해야될 것이 가장 많은 것
//                    //2. 작업 안한지 가장 오래 된것
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
        //tasks중 가장 많은 task가 가장 많은 idle을 만들 수 있다.
        //가장 많이 나온 task로 idle 수를 구한 다음 남은 task들을 idle에 채워 넣는다.
        int maxTask = 0, m = tasks.size();
        int numpeak = 0;

        //가장 숫자가 많은 task에 대한 값을 저장한다.
        for (auto& c : tasks) {
            maxTask = max(maxTask, ++task[c]);
        }

        //가장 숫자가 많은 task의 수를 구한다.
        for (auto& c : task) {
            if (c.second == maxTask) {
                numpeak++;
            }
        }
        //(가장 숫자가 많은 task의 수 - 1) * (cool time + 1) + 가장 숫자가 많은 task의 수
        return max(m,(maxTask - 1) * (n + 1) + numpeak);
=======
    priority_queue<char> q;                  //작업 queue
    unordered_map<char, int> coolDown;   //pop 후 coolDown Time
    unordered_map<char, int> m;          //tasks의 원소 및 갯수
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
            cout << "종료한 task : " << task << endl;
            if (coolDown.size() > 0) {
                cout << "쿨타임 현황" << endl;
                for (auto it = coolDown.begin(); it != coolDown.end(); it++) {
                    cout << it->first << ", " << it->second << endl;
                }
            }
            q.pop();
            if (task != ' ') {
                for (auto it = m.begin(); it != m.end(); it++) {
                    //실행해야 되는 task가 남아 있는지 확인
                    cout << it->first << ", " << it->second << endl;
                    if (it->second > 0) {
                        nextStep = true;
                        //있다면 쿨탐 확인
                        for (int i = 0; i < coolDown.size(); i++) {
                            /*if (it->first == coolDown[i].first && coolDown[i].second > 0) {
                                coolTime = true;
                                break;
                            }*/
                        }
                        //쿨탐 없는게 있다면 q에 push후 m에서 1 감소
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
            //쿨타임 감소
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
