#include<iostream>
#include<vector>

using namespace std;

/*
	�Է¹��� u�� A + now*n�� ���� ��� counting
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, A = 0, D = 0;
	cin >> N >> A >> D;

	int now = A, cnt = 0;
	for (int i = 0; i < N; i++) {
		int u = 0;
		cin >> u;
		if (u == now) {
			cnt++;
			now += D;
		}
	}

	cout << cnt << endl;

	return 0;
}