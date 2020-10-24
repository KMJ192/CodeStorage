//https://programmers.co.kr/learn/courses/30/lessons/42840
//프로그래머스 완전탐색.모의고사

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
    vector<int> result;
    int dap = 0, s = 0;

    //첫번째 수포자 계산
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

    //두번째 수포자 계산
    //2,1,2,3,2,4,2,5,2,1,2,3,2,4,2,5...
    //0,1,2,3,4,5,6,7,8,9,10..
    //0,1,0,1,0,1,0,1,0,1,0
    for (int i = 0; i < answer.size(); i++) {
        
        if (i % 2 == 0) {
            //i번째가 짝수일경우 수포자의 정답은 2

        }
        else {
            //수포자의 정답은 dap
            if (dap == 2) {
                dap = 3;
            }
            else {
                dap++;
            }
        }
    }

    //세번째 수포자 계산
    //3,3,1,1,2,2,4,4,5,5,3,3,1,1,2,2,4,4,5,5...
    for (int i = 0; i < answer.size(); i++) {
        //어케 계산 할까 

    }

    return answer;
}

int main() {

    vector<int> answers = { 1, 2, 3, 4, 5 };
    solution(answers);

    return 0;
}