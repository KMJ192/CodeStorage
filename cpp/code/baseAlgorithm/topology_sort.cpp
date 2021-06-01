#include<iostream>
#include<vector>
#include<queue>

using namespace std;

template<class T>
class TopologySort{
private:
	
public:
	TopologySort() {};
	~TopologySort() {};

	vector<T> run(vector<vector<T>> graph) {
		vector<T> answer;
		vector<T> incoming(graph.size());
		vector<vector<T>> outgoing(graph.size());

		for (int i = 0; i < graph.size(); i++) {
			incoming[graph[i][1]]++;
			outgoing[graph[i][0]].push_back(graph[i][1]);
		}
		cout << endl;
		for (int i = 0; i < graph.size(); i++) {
			cout << "³ëµå " << i << " : ";
			cout << "incoming : " << incoming[i] << ", outgoing : ";
			for (int j = 0; j < outgoing[i].size(); j++) {
				cout << outgoing[i][j] << " ";
			}
			cout << endl;
		}

		queue<T> entry_point;
		for (int i = 0; i < graph.size(); i++) {
			if (incoming[i] == 0) {
				entry_point.push(i);
			}
		}

		while (!entry_point.empty()) {
			T node = entry_point.front();
			entry_point.pop();
			answer.push_back(node);
			for (int i = 0; i < outgoing[node].size(); i++) {
				incoming[outgoing[node][i]]--;
				if (incoming[outgoing[node][i]] == 0) {
					entry_point.push(outgoing[node][i]);
				}
			}
		}

		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << endl;
		}

		return answer;
	}
};

int main() {
	vector<vector<int>> graph = {
		{0, 1},
		{0, 2},
		{1, 3},
		{2, 3},
		{3, 5},
		{4, 5},
		{1, 6}
	};

	TopologySort<int> s;
	s.run(graph);

	return 0;
}