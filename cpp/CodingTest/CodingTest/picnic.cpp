#include"default.h"

//1. �� �׽�Ʈ���̽� �Է�
//�л����� ģ������ ���� �Է�
//ģ���� ���л��� ��ȣ �Է�
//����ģ���� �л����� ¦���� �� �ִ� ����� ���� ���
//�ߺ����� �л��� ���� ���� ���� ���� ��
//�������� Ȯ��

//3
//2 1
//0 1

bool areFriends[10][10]; //2���� ���� ģ������ Ȯ�� => true�� ��� ģ��

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 0;
	//1. �� �׽�Ʈ ���̽� �Է�
	cin >> tc;
	for (int i = 0; i < tc; ++i) {
		int sC = 0, pairC = 0;
		//1. �л����� ģ������ ���� �Է¹���
		cin >> sC >> pairC;
		//2. ģ���� �л��� �Է¹���
		for (int j = 0; j < pairC; ++j) {
			int f1, f2;
			cin >> f1 >> f2;
		}
	}

	return 0;
}