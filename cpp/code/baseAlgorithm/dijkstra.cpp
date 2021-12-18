#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dijkstra(vector<vector<int>>& path, int src, int dst) {
  sort(path.begin(), path.end());
  priority_queue<int> q;
  for (int i = 0; i < q.size(); i++) {
    
  }
  
}

int main() {
  // from to weight
  vector<vector<int>> path = {
    { 1, 2, 1 },
    { 1, 3, 3 },
    { 2, 3, 6 },
    { 2, 4, 4 },
    { 2, 5, 7 },
    { 3, 4, 3 },
    { 4, 6, 10 },
    { 5, 6, 1 },
  };

  dijkstra(path, 0, 6);

  return 0;
}