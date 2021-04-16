#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, A;
	vector<int> v;
	set<int> s;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A;
		v.push_back(A);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size() / 2; i++) {
		for (int j = i; j < v.size(); j++) {
			if (i == j) continue;
			if (v[i] + v[j] > v[v.size() - 1]) break;
			s.insert(v[i] + v[j]);
		}
	}

	int cnt = 0;
	int visit = 0;
	for (auto it = s.begin(); it != s.end(); it++) {
		if (v[v.size() - 1] < *it) break;
		for (int i = visit; i < v.size(); i++) {
			if (v[i] == *it) {
				visit = i;
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	
	return 0;
}