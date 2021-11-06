#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, low = 0, high = nums.size() - 1;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};

int main() {

    Solution s;
    vector<int> nums = { -1,0,3,5,9,12 };
    cout << s.search(nums, 2);

    return 0;
}