#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        bool flag = false;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == nums[j] && i != j) {
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                cnt += nums[i];
            }
            else flag = false;
        }
        return cnt;
    }
};

int main() {
    vector<int> nums = {1, 2};
    Solution a;
    cout << a.sumOfUnique(nums);
    return 0;
}