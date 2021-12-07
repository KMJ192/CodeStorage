#include <iostream>
#include <vector>

using namespace std;

class Solution {
  using ii = pair<int, int>;
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ret;
    if (nums.size() == 2 && nums[0] + nums[1] != target) return ret;

    for (int i = 0; i < nums.size(); i++) {

    }
  }

  void recursion(vector<int>& nums, int target, ii pointer) {
    
  }
};

int main() {
  Solution s;
  vector<int> nums = { 2, 7, 11, 15 };
  s.twoSum(nums, 9);
  return 0;
}