/*
  18:41 ~ 19:11

  i: pc 갯수 integer type -> n, connected 정보 number type 2d array
  o: 최소 수정 갯수 integer type
  c
    1 <= n <= 10^5
    1 <= connections.length <= min(n*(n-1)/2, 10^5)
    connections[i].length == 2
    0 <= connections[i][0], connections[i][1] < n
    connections[i][0] != connections[i][1] -> 같은 pc는 연결 x
    There are no repeated connections. -> unique connection
    No two computers are connected by more than one cable.
  e
    n == 1 => 0 return
  s
    n = 6
    connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]

    0 -> 1
      -> 2
      -> 3
    1 -> 2
      -> 3
    4 5
  vector<int> arr(6, 0);
  [0, 0, 0, 0, 0, 0]
  for (auto i : connections) {
    arr[i[0]]++;
    arr[i[1]]++;
  }
   0  1  2  3  4  5
  [3, 2, 2, 2, 0, 0]
  // connection 존재여부 => 2
  // 연결 가능 여부

  // 남는 connection 갯수, 연결해야될 pc 갯수
  list 만들어서
  0 - 1 - 2  3
    -1
  connection => 돌면서 list만들고
  list dfs => 
  
  s
  t
*/


#include <iostream>
#include <vector>

struct List {
  int val;
  List* next;
  List() : val(0), next(nullptr) {}
  List(int value) : val(value), next(nullptr) {}
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

      List* head = new List();
    }
};

int main() {


  return 0;
}