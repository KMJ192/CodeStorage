#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<string> leftShift(vector<string> v) {
	vector<string> tmp;
	for (int i = 1; i < v.size(); i++) {
		tmp.push_back(v[i]);
	}
	tmp.push_back(v[0]);
	return tmp;
}

int solution(vector<string> v, int k) {
	set<string> s;
	
	cout << endl;
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
	s.size();
	return s.size();
}

int main() {
	int n, k;
	string t;
	vector<string> v;
	cin >> n; //카드의 갯수
	cin >> k; //선택할 카드의 수
	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}
	cout << solution(v, k);

	return 0;
}