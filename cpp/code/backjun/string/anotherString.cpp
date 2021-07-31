//https://www.acmicpc.net/problem/11478

/*
	10:29 ~ 10:59

	input
	 - 문자열 s
	output
	 - 문자열로 만들수 있는 문자열의 unique 값
	constraint
	 - 소문자,
	 - 길이가 0 <= S <= 1000
	edge case
	 - 문자열이 없는것

	 abcd
	 a ab abc abcd
	 b bc bcd
	 c cd
	 d

*/

#include<iostream>
#include<string>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s = "";
	cin >> s;
	if (!s.size()) {
		cout << 0 << "\n";
		return 0;
	}
	set<string> dictionary;
	for (int i = 0; i < s.size(); i++) {
		int n = 0;
		for (int j = i; j < s.size(); j++) {
			n++;
			string ss = s.substr(i, n);
			dictionary.insert(ss);
		}
	}

	for (auto it = dictionary.begin(); it != dictionary.end(); it++) {
		cout << *it << endl;
	}
	cout << dictionary.size() << "\n";

	return 0;
}