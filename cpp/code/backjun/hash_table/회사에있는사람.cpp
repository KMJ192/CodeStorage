#include<iostream>
#include<set>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int personCnt = 0;
	string person[2];
	set<string> state;

	cin >> personCnt;
	for (int i = 0; i < personCnt; i++) {
		cin >> person[0] >> person[1];
		if (person[1] == "enter") {
			state.insert(person[0]);
		}
		else {
			state.erase(person[0]);
		}
	}
	for (auto it = state.rbegin(); it != state.rend(); it++) {
		cout << *it << "\n";
	}

	return 0;
}