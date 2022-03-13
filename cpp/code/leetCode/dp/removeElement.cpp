#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int j = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
          nums[j] = nums[i];
          j++;
        }
      }
      
      return j;      
    }
};

int main() {
  Solution s;
  vector<int> nums = { 3, 3, 2, 3 };
  s.removeElement(nums, 3);

  return 0;
}