#include<iostream>
#include<queue>

#define MAX_VALUE 1001
int graph[MAX_VALUE][MAX_VALUE];
int visited[MAX_VALUE];
int n, m, v;

using namespace std;

void dfs(int v) {
	//node출력
	cout << v << " ";
	//방문했던 노드 1 치환
	visited[v] = 1;
	//graph 탐색
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1 || graph[v][i] == 0) continue;
		dfs(i);
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	//방문했던 노드 0으로 치환
	visited[v] = 0;
	while (!q.empty()) {
		cout << q.front() << " ";
		v = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0 || graph[v][i] == 0) continue;
			q.push(i);
			visited[i] = 0;
		}	
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//정점의 개수, 간선의 개수, 정점의 번호 입력
	cin >> n >> m >> v;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;
	}

	//출력
	dfs(v);
	cout << "\n";
	bfs(v);

	return 0;
}