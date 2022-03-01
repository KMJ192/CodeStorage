/**
 * @file QuadTree.cpp
 * @author Kim Myeong Jun (myeongjun222@github.com)
 * @version 0.1
 * @date 2022-03-01
 * 
 * @copyright Copyright (c) 2022
 * 
 * 대량의 좌표 데이터를 메모리 내 압축하여 저장하기위해 사용하는 기법 중 쿼드트리 라는것이 있다
 * 주어진 공간을 항상 4개로 분할하여 재귀적으로 표현한다.
 * 검은색과 흰색밖에 없는 흑백 그림을 압축하여 표현하는것이 있다.
 * 2ⁿ * 2ⁿ 크기의 흑백 그림을 문자열로 압축한다.
 * 1. 모든 픽셀이 검은색일 경우 이 그림의 쿼드트리 압축 결과는 그림의 크기에 관계없이 b
 * 2. 모든 픽셀이 흰색일 경우 이 그림의 쿼드트리 압축 결과는 그림의 크기에 관계없이 w
 * 3. 모든 픽셀의 색이 다르면, 쿼드 트리는 이 그림을 가로 세로로 각각 2등분하여 4개의 조각으로 쪼갠 뒤 쿼드트리 압축
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 1000

class Solution {
public:
  Solution() {}
  ~Solution() {}
  string reverse(string::iterator& it) {
    char head = *it;
    ++it;
    if (head == 'b' || head == 'w') {
      return string(1, head);
    }
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
  }

  void quadTree(vector<string>& quadValue) {
    for (string value: quadValue) {
      cout << value << " => ";
      string::iterator it = value.begin();
      cout << reverse(it) << endl;
    }
  }

};

int main() {
  Solution s;
  int cnt = 4;
  vector<string> quadValue = { "w", "xbwwb", "xbwxwbbwb", "xxwwwbxwxwbbbwwxxxwwbbbwwwwbb" };

  s.quadTree(quadValue);

  return 0;
}