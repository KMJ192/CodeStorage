#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> re;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i != j && nums[i] > nums[j]) cnt++;
            }
            re.push_back(cnt);
        }
        return re;
    }
};

int main() {
    vector<int> nums = {8, 1, 2, 2, 3};
    Solution a;
    a.smallerNumbersThanCurrent(nums);

    return 0;
}