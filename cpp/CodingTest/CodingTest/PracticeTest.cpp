//https://programmers.co.kr/learn/courses/30/lessons/42840
//���α׷��ӽ� ����Ž��.���ǰ��

#include<iostream>
#include <string>
#include <vector>

using namespace std;

//�� �����ڵ��� ���� ��� ����
//1. ù��° ������ ���
//2. �ι�° ������ ���
//3. ����° ������ ���
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> result;
    int dap = 0, s = 0;

    //ù��° ������ ���
    //1,2,3,4,5,1,2,3,4,5...
    for (int i = 0; i < answer.size(); i++) {
        dap++;
        if (dap = answer[i]) {
            s++;
        }
        if (dap == 5) {
            dap = 0;
        }
    }
    
    result[0] = s;
    s = 0;

    //�ι�° ������ ���
    //2,1,2,3,2,4,2,5,2,1,2,3,2,4,2,5...
    //0,1,2,3,4,5,6,7,8,9,10..
    //0,1,0,1,0,1,0,1,0,1,0
    for (int i = 0; i < answer.size(); i++) {
        
        if (i % 2 == 0) {
            //i��°�� ¦���ϰ�� �������� ������ 2

        }
        else {
            //�������� ������ dap
            if (dap == 2) {
                dap = 3;
            }
            else {
                dap++;
            }
        }
    }

    //����° ������ ���
    //3,3,1,1,2,2,4,4,5,5,3,3,1,1,2,2,4,4,5,5...
    for (int i = 0; i < answer.size(); i++) {
        //���� ��� �ұ� 

    }

    return answer;
}

int main() {

    vector<int> answers = { 1, 2, 3, 4, 5 };
    solution(answers);

    return 0;
}