#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//2분탐색
bool binarySearch(int start, int end, int object, vector<int> v) {
	if (start > end) return false;

	int middle = (start + end) / 2;

	if (v[middle] == object) return true;
	else if (v[middle] < object) return binarySearch(middle + 1, end, object, v);
	else return binarySearch(start, middle - 1, object, v);

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N= 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		vector<int> v(N);
		for (int j = 0; j < N; j++) {
			cin >> v[j];
		}
		sort(v.begin(), v.end());

		//기준이 되는 2번째 수첩
		cin >> N;
		for (int j = 0; j < N; j++) {
			int object = 0;
			cin >> object;
			if (binarySearch(0, v.size() - 1, object, v)) cout << "1\n";
			else cout << "0\n";
		}
	}

	return 0;
}