#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

//��ü ��, ����, ������
//������ 1��
int solution(int n, vector<int> lost, vector<int> reserve) {
    //���� �� �迭
    vector<int> compare;
    int sum = 0;

    //=====================
    vector<int> temp;
    int x = 0, z = 0;
    //=====================
    
    for (int i = 0; i < n; i++) {
        //cout << i << endl;
        if (reserve[x] > lost[z]) {
            temp.push_back(lost[z]);
            if ((lost.size() -1) == z)
                z++;
        }
        else {
            temp.push_back(reserve[x]);
            if ((reserve.size() - 1) != x)
                x++;
        }
    }

    for (vector<int>::iterator it = temp.begin(); it != temp.end(); it++) {
        cout << *it << endl;
    }

    int answer = 0;
    return answer;
}

int main() {

    vector<int> lost = { 2, 4 };
    vector<int> reserve = { 1, 3, 5 };

    solution(5, lost, reserve);

    return 0;
}