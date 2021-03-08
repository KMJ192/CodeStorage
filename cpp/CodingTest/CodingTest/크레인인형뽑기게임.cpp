#include<iostream>
#include<vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> move) {
	int answer = 0;
	vector<int> basket;
	int boardSearch = 0;
	int temp = 0;
	bool breakFlag = false;
	for (int i = 0; i < move.size(); i++) {
		boardSearch = move[i] - 1;
		for (int n = 0; n < board.size(); n++) {
			if (board[n][boardSearch] != 0) {
				//board Loop¹® break;
				if (temp == board[n][boardSearch]) {
					basket.pop_back();
					answer += 2;
				}
				else {
					basket.push_back(board[n][boardSearch]);
				}
				temp = basket.back();
				board[n][boardSearch] = 0;
				break;
			}
		}
	}

	return answer;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> board;
	vector<int> move;

	board = {
		{0,0,0,0,0},
		{0,0,1,0,3},
		{0,2,5,0,1},
		{4,2,4,4,2},
		{3,5,1,3,1}
	};
	move = { 1, 5, 3, 5, 1, 2, 1, 4 };

	cout << solution(board, move) << endl;


	return 0;
}