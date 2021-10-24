/*
	time: 11:46 ~ 12:14
	����
		���ٸ��� ���ε� ��ġ
		���ε��� ���̰� �������� ������ ���� ��
		���ٸ� ��ü�� ���� ����� �ְ�, ������ �������� �鵵�� ��ġ
		���ε��� ����� �ִ� �Ÿ��� ���ε��� ���̿� ���
	input
		���ٸ� ����
		���ε��� ����
		���ε��� ��ġ
	output
		���ٸ��� ���� ��ŭ ���� ���� ���ε��� �ּ� ���̸� ���
	constraint
		1 <= ���ٸ� ���� <= 100000
		1 <= ���ε� ���� <= N
		���ε��� ��ġ�� ������������ �Է��ؾ� �ȴ�.
	edge case
	solution
		���ε� ������ ������ ���� �ʵ���
		���ٸ��� ���̸� boolean array��
		���ε��� ���� ���ߴ� ���̸� true�� ��ȯ
		���ε��� ���̸� ���̸鼭 �迭���� false�� ���ٸ�
		���ε� ���̸� ��ȯ

		time: O(N * height)
		space:
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 100000

int N = 0;			// ���ε��� ����
int M = 0;			// ���ε��� ����
vector<int> x;	// ���ε��� ��ġ��

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

	// left ~ right���� �� �̺�Ž����  �� �� �ִ��� �Ǻ�
	// mid = (left + right) / 2�� �̿��Ͽ�,
	// mid�� ���̷� ���ٸ��� ���� ���� �� ���ٸ� mid���� �� ū��(left = mid + 1)
	// mid�� ���̷� ���ٸ��� ���� ���� �� �ִٸ� mid���� �� ������(right = mid - 1)�� �õ��Ѵ�.
	// ���̻� �õ��� �� ���� ��Ȳ(left > right)�� �� ��� ���α׷� ����

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