#include<iostream>

using namespace std;

bool areFriends[10][10]; //2명이 서로 친구인지 확인 => true일 경우 친구
int n, m;//학생수, 친구쌍 수

//taken[i] => i번째 학생이 짝을 찾았으면 1, 아니면 0
int countParings(bool taken[10]) {

	//남은 학생 중 번호가 가장 빠른 학생을 찾음
	int firstFree = -1;
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) return 1; // 모든학생이 짝을 찾음 종료

	//firstFree 학생과 짝지을 학생을 결정
	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countParings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//전체 테스트케이스 입력
	int testCase;
	cin >> testCase;

	//테스트케이스만큼 반복
	for (int i = 0; i < testCase; i++) {
		//학생수(n), 친구쌍수(m) 입력
		cin >> n >> m;
		memset(areFriends, 0, sizeof(areFriends)); //기존내용 초기화

		//친구쌍 수 만큼 반복
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			areFriends[a][b] = areFriends[b][a] = true; //친구쌍 각각 입력(반복제거)
		}

		bool taken[10];
		memset(taken, 0, sizeof(taken)); //기존내용 초기화
		cout << countParings(taken) << "\n";
	}

	return 0;
}