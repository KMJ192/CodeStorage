// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>

// using namespace std;

// void dijkstra(vector<vector<int>>& path, int src, int dst) {
//   sort(path.begin(), path.end());
//   priority_queue<int> q;
//   for (int i = 0; i < q.size(); i++) {

//   }
// }

// int main() {
//   // from to weight
//   vector<vector<int>> path = {
//     { 1, 2, 1 },
//     { 1, 3, 3 },
//     { 2, 3, 6 },
//     { 2, 4, 4 },
//     { 2, 5, 7 },
//     { 3, 4, 3 },
//     { 4, 6, 10 },
//     { 5, 6, 1 },
//   };

//   dijkstra(path, 0, 6);

//   return 0;
// }

#include <iostream>
#include <queue>
#include <vector>
#include <string>

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
    int cur = pq.top().second;
    int weight = -pq.top().first;
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