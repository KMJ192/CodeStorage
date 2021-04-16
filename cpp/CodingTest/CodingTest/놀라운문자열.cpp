#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>

using namespace std;
int factorial(int n) {
	int re = 0;
	int tmp = n;
	for(int i = 0; i < n; i++){
		re += tmp--;
	}
	return re;
}

int main() {
	string tmp;
	bool b;
	map<string, bool> m;

	while (getline(cin, tmp)) {
		if (tmp == "*") break;
		if (tmp.size() <= 2) {
			m.insert(pair<string, bool>(tmp, true));
			continue;
		}
		set<string> s;
		for (int i = 0; i < factorial(tmp.size() - 1); i++) {
			if (i > tmp.size() - 1) break;
			if (s.find(to_string(tmp[i] + tmp[i + 1])) != s.end()) {
				b = false;
				break;
			}
			s.insert(to_string(tmp[i] + tmp[i + 1]));
		}
		m.insert(pair<string, bool>(tmp, b));
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << ", " << it->second << endl;
	}

	return 0;
}