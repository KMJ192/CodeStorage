/**
 * @file unionFind.cpp
 * @brief 
 * @version 0.1
 * @date 2022-04-09
 * 
 * @copyright Copyright (c) 2022
 * 어떤 노드가 그래프에 속해있는지 확인하는 알고리즘
 * 부모를 합칠때 일반적으로 더 작은 값쪽으로 합침
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// 부모 노드를 찾는 함수
int getParent(int parent[], int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b) {
  a = getParent(parent, a);
  b = getParent(parent, b);

  if (a < b) parent[b] = a;
  else parent[a] = b;
}

// 같은 부모를 가지는지 확인
bool findParent(int parent[], int a, int b) {
  a = getParent(parent, a);
  b = getParent(parent, b);
  if (a == b) return true;
  return false;
}

int main() {
  int parent[11];
  for(int i = 1; i <= 10; i++) {
    parent[i] = i;
  }

  unionParent(parent, 1, 2);
  unionParent(parent, 2, 3);
  unionParent(parent, 3, 4);
  unionParent(parent, 5, 6);
  unionParent(parent, 6, 7);
  unionParent(parent, 7, 8);

  printf("1과 5의 연결 여부 %d\n", findParent(parent, 1, 5));
  unionParent(parent, 1, 5);
  printf("1과 5의 연결 여부 %d\n", findParent(parent, 1, 5));

  return 0;
}