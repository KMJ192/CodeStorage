#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
  순서가 정해져있는 작업을 차례대로 수행해야 될 경우, 그 순서를 결정
*/
vector<int> topologySort(vector<vector<int>> graph) {
  vector<int> sortedItems;
  int len = (int)graph.size();

  vector<int> incomming(len);
  vector<vector<int>> outgoing(len);

  for (int i = 0; i < len; i++) {
    int prev = graph[i][0], next = graph[i][1];
    incomming[next]++;
    outgoing[prev].push_back(next);
  }

  for (int i = 0; i < len; i++) {
    cout << i << "\n";
    cout << "incomming : " << incomming[i] << "\noutgoing : ";
    for (int j = 0; j < outgoing[i].size(); j++) {
      cout << outgoing[i][j] << " ";
    } 
    cout << "\n" << endl;
  }

  queue<int> entryPoint;
  for (int i = 0; i < len; i++) {
    if (incomming[i] == 0) {
      entryPoint.push(i);
    }
  }

  while (!entryPoint.empty()) {
    int node = entryPoint.front();
    entryPoint.pop();
    sortedItems.push_back(node);
    for (int i = 0; i < outgoing[node].size(); i++) {
      int next = outgoing[node][i];
      incomming[next]--;
      if (incomming[next] == 0) {
        entryPoint.push(next);
      }
    }
  }

  return sortedItems;
}

int main() {
  // 선행과목, 후행과목
  vector<vector<int>> graph = {
		{0, 1},
		{0, 2},
		{1, 3},
		{2, 3},
		{3, 5},
		{4, 5},
		{1, 6}
	};

  vector<int> sort = topologySort(graph);
  for (auto node : sort){
    cout << node << endl;
  }

  return 0;
}