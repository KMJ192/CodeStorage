#include<iostream>
#include<vector>
#include<map>

using namespace std;

string dicCompare(string first, string second) {
	if (first > second) return first;
	else return second;
}

string solution(vector<string> &bookName) {
	map<string, int> frequency;
	for (int i = 0; i < bookName.size(); i++) {
		if (frequency.find(bookName[i]) != frequency.end()) {
			int t = frequency.find(bookName[i])->second;
			frequency.find(bookName[i])->second = t + 1;
		}
		else {
			frequency.insert(pair<string, int>(bookName[i], 1));
		}
	}
	int many = 0;
	string answer;
	for (map<string, int>::iterator it = frequency.begin(); it != frequency.end(); it++) {
		if (it->second > many) {
			answer = it->first;
			many = it->second;
		}
		else if (it->second == many && dicCompare(answer, it->first) == answer) {
			answer = it->first;
			many = it->second;
		}
	}
	bookName.clear();

	return answer;
}

int main() {
	int bookCnt = 0;
	string tmp;
	vector<string> bookName;

	cin >> bookCnt;
	for (int i = 0; i < bookCnt; i++) {
		cin >> tmp;
		bookName.push_back(tmp);
		tmp.clear();
	}

	cout << solution(bookName);

	return 0;
}