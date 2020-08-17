//solution : https://programmers.co.kr/learn/courses/30/lessons/42888

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<sstream>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> idmap;

	for (vector<string>::iterator it = record.begin(); it != record.end(); ++it) {
		stringstream ss(*it);
		string cmd, id, name;
		ss >> cmd;
		if (cmd.compare("Enter") == 0) {
			ss >> id >> name;
			idmap[id] = name;
		}
		else if (cmd.compare("Change") == 0) {
			ss >> id >> name;
			idmap[id] = name;
		}
	}

	for (vector<string>::iterator it = record.begin(); it != record.end(); ++it) {
		stringstream ss(*it);
		string cmd, id;
		ss >> cmd;
		if (cmd.compare("Enter") == 0) {
			ss >> id;
			answer.push_back(idmap[id] + "���� ���Խ��ϴ�.");
		}
		else if (cmd.compare("Leave") == 0) {
			ss >> id;
			answer.push_back(idmap[id] + "���� �������ϴ�.");
		}
	}

	return answer;
}

int main() {

	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };

	for (int i = 0; i < solution(record).size(); i++) {
		cout << solution(record)[i] << endl;
	}
	
	return 0;
}