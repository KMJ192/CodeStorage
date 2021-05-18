#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int cnt = 0;
        bool flag = false;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                if (i != j && A[i] == A[j]) {
                    flag = true;
                    break;
                }
            }
            if (flag == true) {
                cnt = A[i];
                break;
            }
        }
        return cnt;
    }
};

int main() {
    vector<int> A = { 5,1,5,2,5,3,5,4 };
    Solution a;
    cout << a.repeatedNTimes(A);
    return 0;
}