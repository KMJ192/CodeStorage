#include<vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	for (int i = 0; i < prices.size(); i++) {
		int count = 0;
		int com = i + 1;
		for (int j = com; j < prices.size(); j++) {
			//현재의 가격(prices[i])와 이후의 가격(prices[j]) 비교
			if (prices[j] < prices[i]) {
				//현재의 가격이 이후의 가격보다 더 클경우 Counter 증가
				count++;
				break;
			}
			else {
				count++;
			}
		}
		answer.push_back(count);
	}

	return answer;
}