#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

//0���� n - 1���� �󺧷� ǥ�õ� �� n���� ���°� �ֽ��ϴ�.
//�Ϻ� �������� �ʼ� ������ ���� �� �ֽ��ϴ�.
//���� ���, prerequisites[i] = [a, b]�� ���, 
//�̴� a������ �����ϱ� ���� ���� b�� �����ؾ� ���� �ǹ��մϴ�.
//��ü ���� ���� �ʼ� �׸� �� ����� �ִ� ���, 
//��� ������ �Ϸ��ϱ� ���� �����ؾ� �ϴ� ���� ������ ��ȯ�մϴ�.
//��ȿ�� �亯�� ������ �ƹ� ����̳� ��ȯ�Ͻʽÿ�.
//��� ������ �Ϸ��� �� ���� ��� �� �迭�� ��ȯ�մϴ�.

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

//��������
//1. incomming ���� node���� ����
//2 .outgoing�� node�� �̵�
//3. outgoing���� �̵��� �ش� node���� incomming ����
//4. �ش� node���� �� ���� outgoing node�� �̵�
//5. 2~4�ݺ�
//6. outgoing�̵��� �ش� node�� incomming�� ���� ��� queue�� push