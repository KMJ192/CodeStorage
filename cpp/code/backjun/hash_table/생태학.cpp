#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, float> m;
	string treeName;
	float total = 0;
	while (getline(cin, treeName)) {
		total++;
		if (m.find(treeName) == m.end()) {
			m[treeName] = 1;
		}
		else {
			m[treeName] += 1;
		}
	}
	cout << fixed;
	cout.precision(4);
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << (it->second / total) * 100 << endl;
	}
	
	return 0;
}