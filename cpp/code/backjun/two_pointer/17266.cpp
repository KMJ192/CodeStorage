/*
	time: 11:46 ~ 12:14
	문제
		굴다리에 가로등 설치
		가로등의 높이가 높을수록 예산이 많이 듦
		굴다리 전체에 빛이 비출수 있고, 예산이 가장적게 들도록 설치
		가로등이 비출수 있는 거리는 가로등의 높이와 비례
	input
		굴다리 길이
		가로등의 갯수
		가로등의 위치
	output
		굴다리의 길이 만큼 빛을 비출 가로등의 최소 높이를 출력
	constraint
		1 <= 굴다리 길이 <= 100000
		1 <= 가로등 갯수 <= N
		가로등의 위치는 오름차순으로 입력해야 된다.
	edge case
	solution
		가로등 사이의 공간이 비지 않도록
		굴다리의 길이를 boolean array로
		가로등의 빛이 비추는 곳이면 true로 변환
		가로등의 높이를 높이면서 배열에서 false가 없다면
		가로등 높이를 반환

		time: O(N * height)
		space:
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 100000

int N = 0;			// 가로등의 높이
int M = 0;			// 가로등의 개수
vector<int> x;	// 가로등의 위치값

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int p = 0;
		cin >> p;
		x.push_back(p);
	}
}

bool isPossible(vector<int>& x, int n, int mid) {
	int len = x.size();
	int darkStart = 0;
	for (int i = 0; i < len; i++) {
		cout << x[i] << endl;
		if (x[i] - mid <= darkStart) {
			darkStart = x[i] + mid;
		}
		else break;
	}

	return n - darkStart <= 0;
}

int solution() {
	int height = 0;

	// left ~ right범위 내 이분탐색을  할 수 있는지 판별
	// mid = (left + right) / 2을 이용하여,
	// mid의 높이로 돌다리를 전부 밝힐 수 없다면 mid보다 더 큰값(left = mid + 1)
	// mid의 높이로 돌다리를 전부 밝힐 수 있다면 mid보다 더 작은값(right = mid - 1)을 시도한다.
	// 더이상 시도할 수 없는 상황(left > right)이 될 경우 프로그램 종료

	int left = 1, right = N;
	int mid = 0, ans = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (isPossible(x, N, mid)) {
			height = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	return height;
}