//¿Á«Æ¿Ã
#include<iostream>
#include<string>
#include<set>
#include<map>

using namespace std;

int factorial(int n) {
	int re = 0;
	int tmp = n;
	for (int i = 0; i < n; i++) {
		re += tmp--;
	}
	return re;
}

int main() {
	string tmp;
	map<string, bool> m;

	while (getline(cin, tmp)) {
		if (tmp == "*") break;
		if (tmp.size() <= 2) {
			m.insert(pair<string, bool>(tmp, true));
			continue;
		}
		int cnt = 0;
		bool b = true;
		bool lastPos = false;
		set<string> s;
		while (1) {
			cnt++;
			if (cnt > tmp.size() - 1) {
				cnt = 0;
				continue;
			}
			string casting;
			for (int i = 0; i < tmp.size(); i++) {
				if (i == 1 && i + cnt == tmp.size()) {
					lastPos = true;
					break;
				}
				casting = "";
				if (i + cnt >= tmp.size()) {
					break;
				}
				casting += tmp[i];
				casting += tmp[i + cnt];
				//cout << casting << endl;
				if (s.find(casting) != s.end()) {
					b = false;
					break;
				}
				else {
					s.insert(casting);
				}
			}
			if (b == false) break;
			if (lastPos == true) break;
		}

		m.insert(pair<string, bool>(tmp, b));
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second == true) {
			cout << it->first << " is surprizing." << "\n";
		}
		else {
			cout << it->first << " is NOT surprizing." << "\n";
		}
	}

	return 0;
}