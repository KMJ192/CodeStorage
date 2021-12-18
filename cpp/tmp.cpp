#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 10000

class Dijkstra {
private:
  using ii = pair<int, int>;
  priority_queue<ii> pq;
  vector<ii> path[MAX];
  void dijkstra(vector<int>& table, int start, int dest) {
    table[start] = 0;
    pq.push(ii(0, start));

    while (!pq.empty()) {
      ii top = pq.top();
      int weight = -top.first;
      int node = top.second;
      pq.pop();

      if (table[node] < weight) continue;

      for (int i = 0; i < path[node].size(); i++) {
        ii pathInfo = path[node][i];
        int nextNode = pathInfo.first;
        int nodeDist = weight + pathInfo.second;

        if (table[nextNode] > nodeDist) {
          table[nextNode] = nodeDist;
          pq.push(ii(-nodeDist, nextNode));
        }
      }      
    }
  }

public:
  void buildDijkstra(int nodeCnt, vector<vector<int>>& info, int start, int dest) {
    vector<int> table(nodeCnt + 1, INT_MAX);
    for (int i = 0; i < info.size(); i++) {
      int from = info[i][0], to = info[i][1], price = info[i][2];
      path[from].push_back(ii(to, price));
    }
    
    dijkstra(table, start, dest);

    if ((int)table.size() > dest) {
      cout << table[dest] << endl;
    }
  }
};

int main() {
  // from, to, weight
  vector<vector<int>> info = {
    { 0, 1, 3 },
    { 0, 3, 1 },
    { 1, 2, 7 },
    { 2, 3, 3 },
    { 3, 4, 10 },
    { 3, 5, 1 },
    { 5, 4, 1 }
  };
  int start = 0, dest = 4;
  int nodeCnt = 5;

  Dijkstra d;
  d.run(nodeCnt, info, start, dest);

  return 0;
}