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
