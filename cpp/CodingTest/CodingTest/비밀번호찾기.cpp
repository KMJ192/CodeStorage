#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	string url, password;
	map<string, string> m;
	while (N) {
		N--;
		cin >> url >> password;
		m.insert(pair<string, string>(url, password));
	}
	string extract;
	vector<string> tmp;
	while (M) {
		M--;
		cin >> extract;
		tmp.push_back(m.find(extract)->second);
	}
	for (int i = 0; i < tmp.size(); i++) {
		cout << tmp[i] << "\n";
	}

	return 0;
}