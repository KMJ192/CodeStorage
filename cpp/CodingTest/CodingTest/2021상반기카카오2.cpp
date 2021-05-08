#include<iostream>
#include <string>
#include <vector>

using namespace std;

bool check(vector<string>cell, int x, int y, int vX, int vY) {
    //상
    if (x > 0) {
        if (x - 1 != vX && cell[x - 1][y] == 'P') return false;
    }
    //하
    if (x < cell.size() - 1) {
        if (x + 1 != vX && cell[x + 1][y] == 'P') return false;
    }
    //좌
    if (y > 0) {
        if (y - 1 != vY && cell[x][y - 1] == 'P') return false;
    }
    //우
    if (y < cell[x].size() - 1) {
        if (y + 1 != vY && cell[x][y + 1] == 'P') return false;
    }
    return true;
}

bool nextCheck(vector<string>cell, int x, int y) {
    //상하좌우로 P가 있으면 false
    //상하좌우로 O가 있고 그다음에 P가 있으면 false
    // 
    //상
    if (x > 0) {
        if (cell[x - 1][y] == 'P') return false;
        else if (cell[x - 1][y] == 'O') {
            if (check(cell, x - 1, y, x, y) == false) return false;
        }
    }
    //하
    if (x < cell.size() - 1) {
        if (cell[x + 1][y] == 'P') return false;
        else if (cell[x + 1][y] == 'O') {
            if (check(cell, x + 1, y, x, y) == false) return false;
        }
    }
    //좌
    if (y > 0) {
        if (cell[x][y - 1] == 'P') return false;
        else if (cell[x][y - 1] == 'O') {
            if (check(cell, x, y - 1, x, y) == false) return false;
        }
    }
    //우
    if (y < cell[x].size() - 1) {
        if (cell[x][y + 1] == 'P') return false;
        else if (cell[x][y + 1] == 'O') {
            if (check(cell, x, y + 1, x, y) == false) return false;
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    bool eFlag = false;
    for (int i = 0; i < places.size(); i++) {
        int visited[5][5] = { {0,}, };
        for (int x = 0; x < places[i].size(); x++) {
            for (int y = 0; y < places[i][x].size(); y++) {
                if (places[i][x][y] == 'P') {
                    if (!nextCheck(places[i], x, y)) {
                        answer.push_back(0);
                        eFlag = true;
                        break;
                    }
                }
            }
            if (eFlag == true) {
                break;
            }
        }
        if (eFlag == true) {
            eFlag = false;
        }
        else {
            answer.push_back(1);
        }
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
    return answer;
}

int main() {

    vector<vector<string>> places = {
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"} ,
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
    };

    //vector<vector<string>> places = {
    //    {
    //        "POP", 
    //        "OPO", 
    //        "POP"
    //    },
    //};

    solution(places);

    return 0;
}