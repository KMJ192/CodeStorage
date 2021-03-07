#include "default.h"

//단품을 세트로 코스요리로 구성할것
//이전 손님들이 주문할 때 가장 많이 함께 주문한 단품 메뉴들을 코스요리 메뉴로 구성
//코스요리 메뉴는 최소 2가지 이상의 단품메뉴로 구성
//최소 2명이상의 손님으로부터 주문된 단품메뉴 구성

//각 손님들이 주문한 단품메뉴들이 문자열 형식으로 담긴 배열 orders, 
//"스카피"가 추가하고 싶어하는 코스요리를 구성하는 단품메뉴들의 갯수가 담긴 배열 course가 
//매개변수로 주어질 때, "스카피"가 새로 추가하게 될 코스요리의 메뉴 구성을 문자열 형태로 배열에 담아 return 하도록
//solution 함수를 완성해 주세요.

//1. 메뉴 오름차순 정렬
//2. 만들수 있는 가능한 모든 조합 생성

//입력받은 갯수씩 나누기
int ShareMenu(int course, string menu) {

    int n = 0;
    return n;
}


//orders의 길이 => 손님의 수, course => 배열내 각각 코스요리 조합할 수가 있음
vector<string> solution(vector<string> orders, vector<int> course) {

    //1. 오름차순 정렬
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }

    for (int i = 0; i < course.size(); i++) {
        cout << course[i]  << "개 씩 조합하여 만들기" << "\n";
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

    //cout << "손님의 수를 입력하세요 : ";
    //cin >> n;

    //for (int i = 0; i < n; ++i) {
    //    cout << i << "번째 손님의 주문 구성 입력 : ";
    //    cin >> tmp;
    //    orders.push_back(tmp);
    //}

    //cout << "코스요리를 구성할 단품의 갯수를 입력 : ";
    //cin >> n;

    //for (int i = 0; i < n; ++i) {
    //    cout << i << "번째, 단품을 조합할 갯수 입력 : ";
    //    cin >> m;
    //    course.push_back(m);
    //}

    solution(orders, course);

	return 0;
}