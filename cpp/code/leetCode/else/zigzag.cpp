/**
 * @file Zigzag Conversion
 * @author MyeongJunKim (myeongjun222@github.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-19
 * 
 * @copyright Copyright (c) 2022
 * https://leetcode.com/problems/zigzag-conversion/
 * 문자열을 지그재그로 배치 후 반환
 * constraint
 *  - 1 ≤ s.length ≤ 1000
 *  - 1 ≤ numRows ≤ 1000
 *  - upper-case, row-case, ',', '.'
 * ex) 
 * Input : PAYPALISHIRING
 *   ↓
 * convert(s, numRos);
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *   ↓
 * Output : PAHNAPLSIIGYIR
 * 

PAYPALISHIRINGDSJKAHSDKJHASDK, 10
^         ^
P                 A
A               K H
Y             J   S
P           S     D
A         D       K
L       G         J
I     N           H
S   I             A
H R               S K
I                 D
PAAKHYJSPSDADKLGJINHSIAHRSKID

 */

#include <iostream>
#include <unistd.h>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows <= 1) return s;
    string answer = "";
    int sLen = s.length();
    for (int i = 0; i < numRows; i++) {
      int increment = 2 * (numRows - 1);
      for (int j = i; j < sLen; j += increment) {
        answer += s[j];
        if (i > 0 && i < (numRows - 1) && (j + increment - 2 * i) < sLen) {
          answer += s[j + increment - 2 * i];
        }
      }
    }
    return answer;
  }
};

int main() {
  string s = "PAYPALISHIRING";
  Solution so;
  cout << so.convert(s, 3);
  
  return 0;
}