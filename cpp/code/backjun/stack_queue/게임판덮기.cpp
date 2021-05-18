#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;

int cover() {

	return 0;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//1. Test Case입력
	//2. 입력할 배열의 크기 각각 입력
	int testCase;
	cin >> testCase;							//테스트케이스 입력

	while (testCase--) {
		int vertical, horizontal;
		cin >> vertical >> horizontal;			//가로세로 크기 입력

		assert(vertical <= 20 && horizontal <= 20);
		vector<vector<int>> board(vertical, vector<int>(horizontal, 0));
		for (int i = 0; i < vertical; i++) {
			string elements;
			cin >> elements;
			for (int j = 0; j < horizontal; j++) {
				if (elements[j] == '#') {
					board[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				cout << board[i][j];
			}
			cout << "\n";
		}
	}


	return 0;
}