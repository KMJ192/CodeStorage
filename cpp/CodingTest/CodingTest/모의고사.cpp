#include<iostream>
#include <string>
#include <vector>

using namespace std;

//각 수포자들의 정답 방식 선택
//1. 첫번째 수포자 계산
//2. 두번째 수포자 계산
//3. 세번째 수포자 계산
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> dapVector;
    vector<int> compare;
    int dap = 0, s = 0, index = 0;

    //첫번째 수포자 계산
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

    //두번째 수포자 계산
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
    //세번째 수포자 정답 패턴을 입력하기 위해 vector 초기화
    dapVector.clear();

    //세번째 수포자 계산
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

    //첫번째가 가장 큰경우
    if ((compare[0] > compare[1]) && (compare[0] > compare[2])) {
        answer.push_back(1);
    }
    //두번째가 가장 큰경우
    else if ((compare[1] > compare[0]) && (compare[1] > compare[2])) {
        answer.push_back(2);
    }
    //세번째가 가장 큰경우
    else if ((compare[2] > compare[0]) && (compare[2] > compare[1])) {
        answer.push_back(3);
    }
    //첫번째 두번째 세번째 모두 같은 경우
    else if ((compare[0] == compare[1]) && (compare[0] == compare[2]) && (compare[1] == compare[2])) {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    else {
        //첫번째와 두번째가 같은 경우
        if (compare[0] == compare[1]) {
            answer.push_back(1);
            answer.push_back(2);
        }
        //첫번째와 세번째가 같은 경우
        else if (compare[0] == compare[2]) {
            answer.push_back(1);
            answer.push_back(3);
        }
        //두번째와 세번째가 같은 경우
        else if (compare[1] == compare[2]) {
            answer.push_back(2);
            answer.push_back(3);
        }
    }

    return answer;
}