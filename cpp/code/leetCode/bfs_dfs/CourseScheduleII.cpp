#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  queue<int> entryPoint;
public:
    // 모든 과정을 완료할 수 없을 경우 []반환
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> answer;
      
      vector<vector<int>> outgoing(numCourses);
      vector<int> incoming(numCourses, 0);

      for(auto v: prerequisites){
        incoming[v[0]]++;
        outgoing[v[1]].push_back(v[0]);
      }
      
      for(int i = 0; i < incoming.size(); i++){
        if(incoming[i] == 0) entryPoint.push(i);
      }

      while(!entryPoint.empty()) {
        int node = entryPoint.front();
        entryPoint.pop();
        answer.push_back(node);
        for(int i = 0; i < outgoing[node].size(); i++) {
          int idx = outgoing[node][i]; 
          incoming[idx]--;
          if(incoming[idx] == 0) entryPoint.push(idx);
        }
      }

      vector<int> emptyArr;
      return (answer.size() == numCourses) ? answer : emptyArr;
    }
};

int main() {
  vector<vector<int>> prerequisites = {
    {1,0},
    {2,0},
    {3,1},
    {3,2}
  };

  Solution s;
  vector<int> topologysort = s.findOrder(4, prerequisites);
  for(int i = 0; i < topologysort.size(); i++) {
    cout << topologysort[i] << endl;
  }
  cout << "exit" << endl;

  return 0;
}