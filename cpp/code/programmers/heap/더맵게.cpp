#include<iostream>
#include <vector>
#include<queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    if (scoville.size() <= 1) {
        return -1;
    }
    int answer = 0;
    int first, second;

    priority_queue<int, vector<int>, greater<int>> sort(scoville.begin(), scoville.end());
    while (sort.top() < K && sort.size() > 1) {
        first = sort.top();
        sort.pop();
        second = sort.top();
        sort.pop();
        sort.push(first + (second * 2));

        answer++;
    }
    if (sort.top() < K) {
        return -1;
    }
    return answer;
}

int main() {

    vector<int> scoville = { 12, 1, 2, 3, 9, 10 };
    cout << solution(scoville, 7);
    //priority_queue<int, vector<int>, greater<int>> test;
    //test.push(9);
    //test.push(1);
    //test.push(5);
    //for (int i = 0; i < 3; i++) {
    //    cout << test.top() << endl;
    //    test.pop();
    //}

	return 0;
}