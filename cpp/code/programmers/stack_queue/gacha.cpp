#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	if (!moves.size() || !board.size()) return 0;

	stack<int> basket;
	int cnt = 0;
	int unit = board[0].size();

	for (int n = 0; n < moves.size(); n++) {
		int pos = moves[n] - 1;
		for (int i = 0; i < unit; i++) {
			if (board[i][pos]) {
				if (basket.size() && basket.top() == board[i][pos]) {
					cout << basket.top() << endl;
					basket.pop();
					cnt += 2;
				}
				else {
					basket.push(board[i][pos]);
				}
				board[i][pos] = 0;
				break;
			}
		}
	}
	return cnt;
}

int main() {
	vector<vector<int>> board = {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 3},
		{0, 2, 5, 0, 1},
		{4, 2, 4, 4, 2},
		{3, 5, 1, 3, 1}
	};

	vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };

	solution(board, moves);

	return 0;
}
