#include<iostream>

using namespace std;

bool areFriends[10][10]; //2���� ���� ģ������ Ȯ�� => true�� ��� ģ��
int n, m;//�л���, ģ���� ��

//taken[i] => i��° �л��� ¦�� ã������ 1, �ƴϸ� 0
int countParings(bool taken[10]) {

	//���� �л� �� ��ȣ�� ���� ���� �л��� ã��
	int firstFree = -1;
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) return 1; // ����л��� ¦�� ã�� ����

	//firstFree �л��� ¦���� �л��� ����
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

	//��ü �׽�Ʈ���̽� �Է�
	int testCase;
	cin >> testCase;

	//�׽�Ʈ���̽���ŭ �ݺ�
	for (int i = 0; i < testCase; i++) {
		//�л���(n), ģ���ּ�(m) �Է�
		cin >> n >> m;
		memset(areFriends, 0, sizeof(areFriends)); //�������� �ʱ�ȭ

		//ģ���� �� ��ŭ �ݺ�
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			areFriends[a][b] = areFriends[b][a] = true; //ģ���� ���� �Է�(�ݺ�����)
		}

		bool taken[10];
		memset(taken, 0, sizeof(taken)); //�������� �ʱ�ȭ
		cout << countParings(taken) << "\n";
	}

	return 0;
}