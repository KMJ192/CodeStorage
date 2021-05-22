#include <iostream>
#include <vector>

using namespace std;

#define MIN 5
#define MAX 50

bool check(vector<vector<char>> table, int unit[2][2]) {
	
	for (int i = 0; i < 2; i++) {
		//»ó
		if (unit[0][i] - 1 > 0) {

		}
		//ÇÏ
		//unit [0][i]ÀÎµ¦½º
		

		//ÁÂ
		//¿ì
		//unit [1][i]ÀÎµ¦½º
	}

	return true;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<char>> table;

	int N = 0;
	char row[MAX][MAX] = { { ' ',  }, };
	int unit[2][2] = { {0, 0}, };
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		vector<char> tmp;
		for (int j = 0; j < N; j++) {
			cin >> row[i][j];
			tmp.push_back(row[i][j]);
		}
		table.push_back(tmp);
	}
	cin >> unit[0][0] >> unit[0][1] >> unit[1][0] >> unit[1][1];

	table[unit[0][0]][unit[0][1]] = 'U';
	table[unit[1][0]][unit[1][1]] = 'U';
	
	cout << endl; 
	check(table, unit);

	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[i].size(); j++) {
			cout << table[i][j];
		}
		cout << "\n";
	}

	return 0;
}