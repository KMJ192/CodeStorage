#include<iostream>
#include<vector>
#include<map>

using namespace std;

int solution(map<string, string> m) {
	map<string, int> tCase;
	for (map<string, string>::iterator it = m.begin(); it != m.end(); it++) {
		if (tCase.find(it->second) != tCase.end()) {
			tCase.find(it->second)->second  += 1;
		}
		else {
			tCase.insert(pair<string, int>(it->second, 1));
		}
	}

	int answer = 1;
	for (map<string, int>::iterator it = tCase.begin(); it != tCase.end(); it++) {
		answer *= (it->second + 1);
	}
	answer--;
	return answer;
}

int main() {
	int testCase = 0;
	int cnt = 0;
	string category, clothName;
	map<string, string> m;

	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			cin >> clothName >> category;
			m.insert(pair<string, string>(clothName, category));
		}
		cout << solution(m) << "\n";
		m.clear();
	}

	return 0;
}