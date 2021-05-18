#include<iostream>
#include<vector>
#include<set>

using namespace std;

//첫번째 문제풀이
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	vector<int> tmp1;
//	vector<int> tmp2;
//	int n, m, tmp;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> tmp;
//		tmp1.push_back(tmp);
//	}
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		cin >> tmp;
//		tmp2.push_back(tmp);
//	}
//
//	for (int i = 0; i < m; i++) {
//		bool find = false;
//		for (int j = 0; j < n; j++) {
//			if (tmp1[j] == tmp2[i]) {
//				find = true;
//				cout << "1" << "\n";
//				break;
//			}
//		}
//		if (find == false) {
//			cout << "0" << "\n";
//		}
//	}
//
//	return 0;
//}

//두번째 문제풀이
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<int> tmp1;
	vector<int> tmp2;
	int n, m, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		tmp1.insert(tmp);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		tmp2.push_back(tmp);
	}

	for (int i = 0; i < tmp2.size(); i++) {
		if (tmp1.find(tmp2[i]) != tmp1.end()) {
			cout << "1" << "\n";
			continue;
		}
		cout << "0" << "\n";
	}

	return 0;
}