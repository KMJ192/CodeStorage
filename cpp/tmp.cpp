#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 10000

class Solution {
  using ii = pair<int, int>;
  vector<ii> path[MAX];
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    for (int i = 0; i < flights.size(); i++) {
      int from = flights[i][0], to = flights[i][1], price = flights[i][2];
      path[from].push_back(ii(to, price));
    }
    
    vector<int> table(n, INT_MAX);

    priority_queue<ii> pq;
    table[src] = 0;
    pq.push(ii(0, src));

    while (!pq.empty()) {
      for(int i = 0; i < table.size(); i++) {
        cout << table[i] << endl;
      }
      cout << endl;
      int cur = pq.top().second;
      int weight = -pq.top().first;
      pq.pop();

      if(table[cur] < weight) continue;

      for (int i = 0; i < path[cur].size(); i++) {
        int connect = path[cur][i].first;
        int conDist = weight + path[cur][i].second;

        if(table[connect] > conDist) {
          table[connect] = conDist;
          pq.push(ii(-conDist, connect));
        }
      }
    }


    return -1;
  }
};

int main() {
  Solution s;
  vector<vector<int>> flights = {
    { 0, 1, 100 },
    { 1, 2, 100 },
    { 0, 2, 500 },
    { 2, 3, 100 },
    { 0, 4, 100 }
  };

  s.findCheapestPrice(5, flights, 0, 2, 1);
  return 0;
}