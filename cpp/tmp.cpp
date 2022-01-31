/**
 * @file tmp.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int len = graph.size();
    if (len == 0) return 0;
    if (len == 1 && graph[0].size() == 0) return 0;

    queue<vector<int>> q;

    int answer = pow(2, len) - 1;
    int c = answer;
    vector<vector<int>> dp(len, vector<int>(answer));
    map <int, vector<int>> mp;

    for (int i = 0; i < len; i++) {
      mp[i] = graph[i];
    }
    
    for (int i = 0; i < len; i++) {
      dp[i][1 << i] = 1;
      q.push({i, (1 << i), 0});
    }
    
    while(!q.empty()) {
      vector <int> x  = q.front();
      q.pop();
      
      dp[x[0]][x[1]] = 1;
      if(x[1] == answer)
          return x[2];
      int n = x[0];
      vector <int> nodes = mp[n];
      for(int i = 0 ;  i < nodes.size() ; i++){
        int l = nodes[i];
        int m = (x[1]) |(1 << l);
        if(m == answer)
            return x[2] + 1;
        if(dp[l][m] == 1) {
            continue;
        }
        
        dp[l][m] = 1;
        q.push({l, m, x[2] + 1});
      }
    }
    return -1;
  }
};

int main() {
  vector<vector<int>> graph = {
    { 1, 2, 3 }, // 0번째 
    { 0 }, // 1번째
    { 0 }, // 2번째
    { 0 }  // 3번째
  };

  Solution s;
  cout << s.shortestPathLength(graph);

  return 0;
}