#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 20001
#define INF 987654321

//node, dest, dist
vector<pair<int, int>> path[MAX];
int V, E, start;

void dijkstra(vector<int>& table) {
    priority_queue<pair<int, int>> pq;
    table[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int weight = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (table[cur] < weight) continue;

        for (int i = 0; i < path[cur].size(); i++) {
            int connect = path[cur][i].first;
            int conDist = weight + path[cur][i].second;

            if (table[connect] > conDist) {
                table[connect] = conDist;
                pq.push(make_pair(-conDist, connect));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // node는 1부터 V까지
    cin >> V >> E >> start;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        path[u].push_back(make_pair(v, w));
    }
    V++;

    vector<int> table(V, INF);

    dijkstra(table);

    for (int i = 1; i < V; i++) {
        if (table[i] == INF) cout << "INF\n";
        else cout << table[i] << "\n";
    }

    return 0;
}