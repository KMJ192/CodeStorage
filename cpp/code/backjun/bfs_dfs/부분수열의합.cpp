// 부분수열의 합
/*
	input
	 - 정수의 개수 N
	 - 정수 S
	output
	 - 합이 S가 되는 부분수열의 갯수를 출력
	constraint
	 - 1 <= N <= 20
	 - s <= 1000000
	edge case
	time complexity
	 - O(n^2)
	space complexity
	 - O(n)

	solution
	주어진 숫자들을 합하여 S가 나오는 부분집합의 수

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int c = 0;
void recursion(vector<int>& number, int S, int idx, int next) {
	if (number.size() == idx) return;
	if (next + number[idx] == S) c++;

	recursion(number, S, idx + 1, next);
	recursion(number, S, idx + 1, next + number[idx]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, S, inputNum;
	vector<int> number;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> inputNum;
		number.push_back(inputNum);
	}

	recursion(number, S, 0, 0);

	cout << c << "\n";

	return 0;
}