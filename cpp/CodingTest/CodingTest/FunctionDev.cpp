#include<iostream>
#include<vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> depDate;

    int len = 0;
    if (progresses.size() != speeds.size()) {
        answer.push_back(len);
        return answer;
    }
    else {
        len = progresses.size();
    }

    for (int i = 0; i < len; i++) {
        //�����ؾߵǴ� �۾��� �� ��ŭ Looping
        int deployCount = 0;
        while (1) {
            deployCount++;
            if ((speeds[i] * deployCount) + progresses[i] >= 100) {
                //progresses���� speeds��ŭ ������ �� 100���� Ŭ ���
                break;
            }
        }
        depDate.push_back(deployCount);
    }

    for (vector<int>::iterator it = depDate.begin(); it != depDate.end(); it++) {
        cout << *it << endl;
    }

    for (int i = 0; i < depDate.size(); i++){

    }

    return answer;
}

int main() {

    vector<int> progresses = { 93,30,55 };
    vector<int> speeds= { 1, 30, 5 };

    solution(progresses, speeds);


	return 0;
}