#include"default.h"

//1. 총 테스트케이스 입력
//학생수와 친구쌍의 수를 입력
//친구인 두학생의 번호 입력
//서로친구인 학생들을 짝지을 수 있는 방법의 수를 계산
//중복으로 학생의 수를 세는 문제 피할 것
//기저조건 확인

//3
//2 1
//0 1

bool areFriends[10][10]; //2명이 서로 친구인지 확인 => true일 경우 친구

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 0;
	//1. 총 테스트 케이스 입력
	cin >> tc;
	for (int i = 0; i < tc; ++i) {
		int sC = 0, pairC = 0;
		//1. 학생수와 친구쌍의 수를 입력받음
		cin >> sC >> pairC;
		//2. 친구인 학생을 입력받음
		for (int j = 0; j < pairC; ++j) {
			int f1, f2;
			cin >> f1 >> f2;
		}
	}

	return 0;
}