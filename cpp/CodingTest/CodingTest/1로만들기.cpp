#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, cnt = 0;
	int tmp = 0;
	
	//우선순위
	//1. 3으로 나누는 것
	//2. 2로 나누는 것
	//3. 1씩 감소

	cin >> N;
	cnt = 0;
	while (1) {
		while (N != 1) {
			tmp++;
			if (N % 3 == 0) {
				N /= 3;
			}
			else if (N % 2 == 0) {
				N /= 2;
			}
			else {
				N--;
			}
		}
		if (tmp < cnt) {
			cnt = tmp;
		}
	}
	cout << cnt;

	return 0;
}