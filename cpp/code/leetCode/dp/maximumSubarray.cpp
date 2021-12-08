/*
  Maximum Subarray

  정수 배열이 주어지면 가장 큰 합을 가진 연속 되는 숫자의 합계를 반환함
  반드시 0번째 idx부터 찾아봐야 함.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// iterative
class Solution {
  int recursionMaxSum = 0;
public:
    int iterativeSolution(vector<int>& nums) {
      int maxSum = nums[0], currSum = nums[0];
      for (int i = 1; i < nums.size(); i++) {
        currSum = max(currSum + nums[i], nums[i]);
        maxSum = max(maxSum, currSum);
      }
      return maxSum;
    }

    int recursionSolution(vector<int>& nums, int n) {
      if (n == 1) return nums[0];
      int currSum = max(nums[n - 1], recursionSolution(nums, n - 1) + nums[n - 1]);
      recursionMaxSum = max(currSum, recursionMaxSum);
      return currSum;
    }

    int maxSubArray(vector<int>& nums) {
      recursionMaxSum = nums[0];
      recursionSolution(nums, nums.size());
      return recursionMaxSum;
      // return iterativeSolution(nums);
    }
};

int main() {
  Solution s;
  vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
  cout << s.maxSubArray(v) << endl;
  return 0;
}