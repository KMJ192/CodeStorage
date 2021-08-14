#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool confirm(string object) {
	if (!object.size()) return true;
	if (object.size() % 2) return false;
	if (object[0] == ')') return false;
	if (object[object.size() - 1] == '(') return false;

	stack<char> s;
	s.push(object[0]);
	for (int i = 1; i < object.size(); i++) {
		if (s.size() && s.top() == '(' && object[i] == ')') s.pop();
		else s.push(object[i]);
	}
	if (s.size()) return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> v;

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string basket = "";
		cin >> basket;
		v.push_back(basket);
	}


	for (int i = 0; i < N; i++) {
		bool con = confirm(v[i]);
		if (con)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}