#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

string sub(string s, int pos1, int pos2, int add) {
	string s1 = s.substr(0, pos1 + 1);
	string s2 = s.substr(pos1 + 1, pos2);
	pos2 += add;
	string s3 = s.substr(pos2 + 1);

	//cout << s1 << ", " << s2 << ", " << s3 << endl;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	reverse(s3.begin(), s3.end());
	cout << s1 << ", " << s2 << ", " << s3 << endl;
	return s1 + s2 + s3;
}

string solution(string s) {
	vector<string> v = { "","" };

	v[0] = sub(s, 0, 1, 0);
	for (int i = 0; i < s.size() - 2; i++) {
		for (int j = 1; j < s.size() - 1; j++) {
			if (j + i >= s.size() - 1) continue;
			v[1] = sub(s, i, j, i);
			sort(v.begin(), v.end());
		}
	}
	return v[0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s = "";
	cin >> s;
	cout << solution(s) << "\n";

	return 0;
}