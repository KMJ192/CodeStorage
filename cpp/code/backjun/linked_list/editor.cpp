/*
10 : 38 ~ 11 : 08

	input 
	 - 문자열 : downcase alpabet, 
	 - 명령어의 갯수 : M
	 - M개 만큼의 명령어
	 L D B P+문자열

	output : 
	 - 편집이 된 문자열 반환

	constraint
	 - 0 <= N.length <= 10,000
	 - M 1 ≤ M ≤ 500,000
	 - L D B P+문자열 4가지
	 edge case
	 - N이 없을 경우

*/
#include<iostream>
#include<string>

using namespace std;

#define MAX 50000

string command[MAX] = { "", };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string n = "";
	int M = 0;

	cin >> n;
	cin >> M;
	
	cin.clear();
	for (int i = 0; i <= M; i++) {
		getline(cin, command[i], '\n');
	}

	int cursor = n.size();
	for (int i = 0; i <= M; i++) {
		if (command[i][0] == 'P') {
			//추가
			//abcd
			string tmp1 = n.substr(0, cursor);
			string tmp2 = n.substr(cursor);
			n = tmp1 + command[i][2] + tmp2;
			cursor++;
		}
		else if (command[i][0] == 'L') {
			//커서 왼쪽이동
			if (cursor - 1 > 0) {
				cursor--;
			}
		}
		else if (command[i][0] == 'D') {
			//커서 오른쪽 이동
			if (cursor + 1 < n.size()) {
				cursor++;
			}
		}
		//abcd
		else if (command[i][0] == 'B') {
			//커서 왼쪽 삭제
			string tmp1 = "", tmp2 = "";
			bool dFlag = false;
			if (cursor > 0) {
				tmp1 = n.substr(0, cursor - 1);
				dFlag = true;
			}
			if (cursor < n.size()) {
				tmp2 = n.substr(cursor + 1);
				dFlag = true;
			}
			if (dFlag) cursor--;
			n = tmp1 + tmp2;
		}
	}
	cout << n << endl;
	return 0;
}