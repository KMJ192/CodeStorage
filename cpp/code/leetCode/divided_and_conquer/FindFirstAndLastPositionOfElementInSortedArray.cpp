#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return { -1, -1 };

        vector<int> answer = { -1, -1 };
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] == target) {
                while (nums[start] != target) {
                    start++;
                }
                while (nums[end] != target) {
                    end--;
                }
                answer[0] = start;
                answer[1] = end;
                return answer;
            }
            else if (nums[mid] < target) {
                // ÇÏÀ§ idx Å½»ö
                start = mid + 1;
            }
            else {
                // »óÀ§ idx Å½»ö
                end = mid - 1;
            }
        }

        return answer;
    }
};

int main() {

    vector<int> nums = { 5, 7, 7, 8, 8, 10 };
    Solution s;
    s.searchRange(nums, 8);

    return 0;
}