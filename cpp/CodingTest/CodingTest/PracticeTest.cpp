//https://programmers.co.kr/learn/courses/30/lessons/42840
//���α׷��ӽ� ����Ž��.���ǰ��

#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

//�� �����ڵ��� ���� ��� ����
//1. ù��° ������ ���
//2. �ι�° ������ ���
//3. ����° ������ ���
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> dapVector;
    vector<int> compare;
    int dap = 0, s = 0, index = 0;

    //ù��° ������ ���
    //1,2,3,4,5,1,2,3,4,5...
    for (int i = 0; i < answers.size(); i++) {
        dap++;
        if (dap == answers[i]) {
            s++;
        }

        if (dap == 5) {
            dap = 0;
        }
    }
    compare.push_back(s);

    s = 0;

    //�ι�° ������ ���
    dapVector = { 2,1,2,3,2,4,2,5 };
    for (int i = 0; i < answers.size(); i++) {
        if (dapVector[index] == answers[i]) {
            s++;
        }
        if (index == dapVector.size() - 1) {
            index = 0;
        }
        else {
            index++;
        }
    }

    compare.push_back(s);

    s = 0;
    index = 0;
    //����° ������ ���� ������ �Է��ϱ� ���� vector �ʱ�ȭ
    dapVector.clear();

    //����° ������ ���
    //3,3,1,1,2,2,4,4,5,5,3,3,1,1,2,2,4,4,5,5...
    dapVector = { 3,3,1,1,2,2,4,4,5,5 };
    for (int i = 0; i < answers.size(); i++) {
        if (dapVector[index] == answers[i]) {
            s++;
        }
        if (index == dapVector.size() - 1) {
            index = 0;
        }
        else {
            index++;
        }
    }

    compare.push_back(s);

    //ù��°�� ���� ū���
    if ((compare[0] > compare[1]) && (compare[0] > compare[2])) {
        answer.push_back(1);
    }
    //�ι�°�� ���� ū���
    else if ((compare[1] > compare[0]) && (compare[1] > compare[2])) {
        answer.push_back(2);
    }
    //����°�� ���� ū���
    else if ((compare[2] > compare[0]) && (compare[2] > compare[1])) {
        answer.push_back(3);
    }
    //ù��° �ι�° ����° ��� ���� ���
    else if ((compare[0] == compare[1]) && (compare[0] == compare[2]) && (compare[1] == compare[2])) {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    else {
        //ù��°�� �ι�°�� ���� ���
        if (compare[0] == compare[1]) {
            answer.push_back(1);
            answer.push_back(2);
        }
        //ù��°�� ����°�� ���� ���
        else if (compare[0] == compare[2]) {
            answer.push_back(1);
            answer.push_back(3);
        }
        //�ι�°�� ����°�� ���� ���
        else if (compare[1] == compare[2]) {
            answer.push_back(2);
            answer.push_back(3);
        }
    }

    return answer;
}

int main() {

    vector<int> answers = { 0 };
    vector<int> test = solution(answers);
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << endl;
   }

    return 0;
}