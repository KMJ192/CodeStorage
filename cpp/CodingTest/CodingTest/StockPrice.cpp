#include<vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	for (int i = 0; i < prices.size(); i++) {
		int count = 0;
		int com = i + 1;
		for (int j = com; j < prices.size(); j++) {
			//������ ����(prices[i])�� ������ ����(prices[j]) ��
			if (prices[j] < prices[i]) {
				//������ ������ ������ ���ݺ��� �� Ŭ��� Counter ����
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