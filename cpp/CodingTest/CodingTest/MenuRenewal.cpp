#include "default.h"

//��ǰ�� ��Ʈ�� �ڽ��丮�� �����Ұ�
//���� �մԵ��� �ֹ��� �� ���� ���� �Բ� �ֹ��� ��ǰ �޴����� �ڽ��丮 �޴��� ����
//�ڽ��丮 �޴��� �ּ� 2���� �̻��� ��ǰ�޴��� ����
//�ּ� 2���̻��� �մ����κ��� �ֹ��� ��ǰ�޴� ����

//�� �մԵ��� �ֹ��� ��ǰ�޴����� ���ڿ� �������� ��� �迭 orders, 
//"��ī��"�� �߰��ϰ� �;��ϴ� �ڽ��丮�� �����ϴ� ��ǰ�޴����� ������ ��� �迭 course�� 
//�Ű������� �־��� ��, "��ī��"�� ���� �߰��ϰ� �� �ڽ��丮�� �޴� ������ ���ڿ� ���·� �迭�� ��� return �ϵ���
//solution �Լ��� �ϼ��� �ּ���.

//1. �޴� �������� ����
//2. ����� �ִ� ������ ��� ���� ����

//�Է¹��� ������ ������
int ShareMenu(int course, string menu) {

    int n = 0;
    return n;
}


//orders�� ���� => �մ��� ��, course => �迭�� ���� �ڽ��丮 ������ ���� ����
vector<string> solution(vector<string> orders, vector<int> course) {

    //1. �������� ����
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }

    for (int i = 0; i < course.size(); i++) {
        cout << course[i]  << "�� �� �����Ͽ� �����" << "\n";
        for (int j = 0; j < orders.size(); j++) {
            ShareMenu(course[i], orders[j]);
        }
    }

    vector<string> answer;
    return answer;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> course = {2, 3, 4};

    //int n, m;
    //string tmp;

    //vector<string> orders;
    //vector<int> course;

    //cout << "�մ��� ���� �Է��ϼ��� : ";
    //cin >> n;

    //for (int i = 0; i < n; ++i) {
    //    cout << i << "��° �մ��� �ֹ� ���� �Է� : ";
    //    cin >> tmp;
    //    orders.push_back(tmp);
    //}

    //cout << "�ڽ��丮�� ������ ��ǰ�� ������ �Է� : ";
    //cin >> n;

    //for (int i = 0; i < n; ++i) {
    //    cout << i << "��°, ��ǰ�� ������ ���� �Է� : ";
    //    cin >> m;
    //    course.push_back(m);
    //}

    solution(orders, course);

	return 0;
}