#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    //결과 입력
    vector<int> answer;

    //인덱스별 더하기
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> numbers = {5, 0, 2, 7 };

    solution(numbers);

	return 0;
}