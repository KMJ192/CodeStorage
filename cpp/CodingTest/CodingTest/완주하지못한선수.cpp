#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;

//Parameter
//1 participant : 참여자 명단
//2. completion : 완료자 명단
string solution(vector<string> participant, vector<string> completion) {

    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i]) {
            answer = participant[i];
            return answer;;
        }
    }
    return  participant[participant.size() - 1];
}

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
    vector<string> completion = { "stanko", "ana", "mislav" };

    assert(participant.size() == completion.size() + 1);
    solution(participant, completion);

	return 0;
}