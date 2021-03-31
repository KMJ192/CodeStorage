#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

priority_queue<string> total;
vector<vector<int>> temp;

//��� ���ڿ�, ��� ���ڿ����� �߶󳻾ߵǴ� ��ġ���� ������ִ� �迭
string ExtractString(string object, vector<int> position) {
    if (object.size() < position.size()) return "";
    int cnt = 0;
    string tmp;

    for (int n = 0; n < object.size(); n++) {
        if (cnt < position.size()) {
            if (n == position[cnt]) {
                cnt++;
                continue;
            }
        }
        tmp = tmp + object[n];
    }
    return tmp;
}

//��� ���ڿ�(�迭),  �迭���� ���� �湮�� ��ġ���� ���� �迭
//�迭�� ���� == 1Cycle�� ��� ���ڿ����� �湮�� ������ ����
//ù��°�� �ٶ󺸴� ������ ��ġ�� �������� ��ġ���� ���� ����Լ� �����Ű��
void Permutation(string object, vector<int> position, int count) {
    count++;
    if (position.size() >= object.size()) return; //��尡 �迭���� ũ�� �ȵȴ�.
    cout << object.size() << endl;
    //���⼭ position �迭�� �߸����ߵ�
    //#######################################
    for (int i = 0; i < position.size(); i++) {
        cout << position[i];
    }
    cout << endl;
    //#######################################

    temp.push_back(position);
    position.back() = position.back() + 1;

    //Ž������ ���� �� ���� ������ ���Ұ� Ž���ؾ� �� ���ڿ��� �������� �ѱ� ���
    if (position.back() > (object.size() - 1)) {
        return;
        /*position[position.size() - 2] = position[position.size() - 2] + 1;
        position.back() = position[position.size() - 2] + 1;*/
    }
    
    //Ž������ ���� �� ���� ù��°�� ���ҿ� ������ ���� ���� ������ ���� ������ Ž��
    while (position[0] <= (object.size() - position.size())) {
        Permutation(object, position, count);
    }
    cout << count << "��° �Լ� �Ϸ�!" << endl;
}

string solution(string number, int k) {
    vector<int> tmp;
    for (int i = 0; i < k; i++) {
        tmp.push_back(i);
    }
    Permutation(number, tmp, 0);
    
    string answer = "";
    return answer;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution("1231234", 3);

    return 0;
}