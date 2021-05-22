#include <iostream>
#include<queue>

using namespace std;

#define MAX 1001

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, k = 0;
	int a[MAX] = { 0, };
	queue<int> q;

	cin >> N >> k;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}

	q.push(k);
	while (!q.empty()) {
		a[q.front()]--;
		if (a[q.front()] == 0) {
			cout << k << " ";
		}
		q.pop();
		
		for (int i = 1; i <= N; i++) {
			k++;
			if (k > N) k = 1;
			if (a[k] != 0) { 
				q.push(k);
				break;
			}
		}
	}

	return 0;
}