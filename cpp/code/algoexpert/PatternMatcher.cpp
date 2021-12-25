/*
  8:07 ~ 8:37
  I
    string type pattern, string
  O
    string type array
  C
    - pattern x, y
    - none matching retrun []
  E??
  S
    xxy
    gogopowerrangergogopowerranger
    
    gogogoa

    yxy
    gopowerrangergo

  Time
  Space
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  vector<vector<string>> table;
public:
  /*
    xxyxxy, 
    gogopowerrangergogopowerranger
    ^                        ^^^^^
  */ 
  void patternMatcher(string pattern, string str) {
    vector<int> pointer(pattern.size()); // [0,1,2,3,4,5]
    for(int i = 0; i < pointer.size() - 1; i++) {
      pointer[i] = i;
    }
    pointer[pointer.size() - 1] = str.size() - 1;

    while (pointer[pointer.size() - pattern.size()]) {
      for (auto i : pointer) {

      }
    }
    
  }
};


int main() {

  return 0;
}