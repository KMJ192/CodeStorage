#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int>& height) {
    int len = height.size();
    int answer = 0;
    int left = 0, right = len - 1;
    int leftMax = 0, rightMax = 0;
    
    while (left <= right) {
      if (height[left] <= height[right]) {
        if (leftMax < height[left]) leftMax = height[left];
        else answer += leftMax - height[left];
        left++;
      } else {
        if (rightMax <= height[right]) rightMax = height[right];
        else answer += rightMax - height[right];
        right--;
      }
    }
    
    return answer;
  }
};

int main() {
  vector<int> height = { 4,2,0,3,2,5 };

  Solution s;
  cout << s.trap(height) << endl;

  return 0;
}