#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

//0부터 n - 1까지 라벨로 표시된 총 n개의 강좌가 있습니다.
//일부 과정에는 필수 조건이 있을 수 있습니다.
//예를 들어, prerequisites[i] = [a, b]인 경우, 
//이는 a과정을 시작하기 전에 과정 b를 수강해야 함을 의미합니다.
//전체 과정 수와 필수 항목 쌍 목록이 있는 경우, 
//모든 과정을 완료하기 위해 수강해야 하는 과정 순서를 반환합니다.
//유효한 답변이 많으면 아무 대답이나 반환하십시오.
//모든 과정을 완료할 수 없는 경우 빈 배열을 반환합니다.

class Solution {
private:
    queue<int> q;
    map<int, int> priority;
    int count = 0;

public:
    void dfs(int numCourses, vector<vector<int>>& prerequisites, map<int, int> priority) {
        for (auto it = priority.begin(); it != priority.end(); it++) {
            cout << it->first << ", " << it->second << endl;
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> answer;
        for (int i = 0; i < prerequisites.size(); i++) {
            priority.insert(pair<int, int>(prerequisites[i][0], -1));
            priority.insert(pair<int, int>(prerequisites[i][1], -1));
        }
        auto it = priority.begin();
        dfs(numCourses, prerequisites, priority);


        return answer;
    }
};

int main() {
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    Solution s;
    s.findOrder(4, prerequisites);

    return 0;
}

//[[1, 0], [2, 0], [3, 1], [3, 2], [5, 1], [6, 1], [5, 2]]
//i
//{
//
//    0: {
//        incoming: []
//        outgoing : [1, 2]
//}
//}
//    1 : {
//        incoming: [0]
//        outgoing : [3, 5, 6]
//      }
//    2 : {
//        incoming: [0]
//        outgoing : [3, 5]
//    }
//    3 : {
//        incoming: [1, 2]
//        outgoing : [] ,
//    }
//    5: {
//        incoming: [1, 2]
//        outgoing : []
//     }
//     6: {
//        incoming: [1]
//        outgoing : []
//     }

//}
//[0, -1]
//
//
//0 -> 1 -> 3
//       1 -> 5
//       1 -> 6
//          -> 2 -> 3
//              2 -> 5

//위상정렬
//1. incomming 없는 node부터 시작
//2 .outgoing의 node로 이동
//3. outgoing으로 이동후 해당 node에서 incomming 삭제
//4. 해당 node에서 그 다음 outgoing node로 이동
//5. 2~4반복
//6. outgoing이동한 해당 node의 incomming이 없을 경우 queue에 push