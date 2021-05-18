#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class TopologySort {
private:
    queue<int> q;
    int visited[100];
public:
    void dfs(vector<vector<int>>& isConnected) {
        
    }

    void bfs(vector<vector<int>>& isConnected) {
        //isConnected의 각 원소별 0번 원소 ~ (isConected.size()-1)번 원소 별 진입점이 0인 정점 모두 삽입
        //  진입점이 0인 정점이 없는 경우는 안됨
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {

            }
        }
    }
};

//Topology sorting algorithm
//1. 진입차수가 0인 정점모두 큐에 삽입
//2. 큐에서 원소를 꺼내 연결된 모든 간선을 제거
//3. 간선을 제거하여 진입차수가 0이 된 정점을 큐에 삽임
//4. 큐가 빌때 까지 1 ~ 3 반복

int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
        //{1,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
        //{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        //{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        //{0,0,0,1,0,1,1,0,0,0,0,0,0,0,0},
        //{0,0,0,0,1,0,0,0,0,1,1,0,0,0,0},
        //{0,0,0,1,0,1,0,0,0,0,1,0,0,0,0},
        //{0,0,0,1,0,0,1,0,1,0,0,0,0,1,0},
        //{1,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
        //{0,0,0,0,0,0,1,1,1,0,0,0,0,1,0},
        //{0,0,0,0,1,0,0,0,0,1,0,1,0,0,1},
        //{0,0,0,0,1,1,0,0,0,0,1,1,0,0,0},
        //{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
        //{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
        //{0,0,0,0,0,0,1,0,1,0,0,0,0,1,0},
        //{0,0,0,0,0,0,0,0,0,1,0,0,0,0,1}
    };

    TopologySort s;
    s.bfs(isConnected);

    return 0;
}