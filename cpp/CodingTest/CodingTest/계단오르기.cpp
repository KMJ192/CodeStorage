//¿Á«Æ¿Ã
#include<iostream>
#include<vector>

using namespace std;

int calculate(vector<int> s) {
	int cnt = 0;

	return cnt;
}

int main() {
	int stairsCnt, tmp;
	vector<int> stairsPoint;

	cin >> stairsCnt;
	while (stairsCnt) {
		stairsCnt--;
		cin >> tmp;
		stairsPoint.push_back(tmp);
	}
	cout << calculate(stairsPoint);

	return 0;
}