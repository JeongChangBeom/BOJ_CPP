//boj7569번_토마토_그래프

#include<iostream>
#include<queue>

using namespace std;

int graph[1001][1001];

queue<pair<int, int>> q;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;

void BFS() {
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = a + dx[i];
			int next_y = b + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && graph[next_x][next_y] == 0) {
				q.push({ next_x,next_y });
				graph[next_x][next_y] = graph[a][b] + 1;
			}
		}
	}
}

int main() {
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];

			if (graph[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}

	BFS();

	int result = 0;
	bool check = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				check = true;
			}
			result = max(result, graph[i][j]);
		}
	}

	if (check) {
		cout << -1;
	}
	else {
		cout << result - 1;
	}

	return 0;
}