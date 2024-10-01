//boj13565번_침투_그래프

#include<iostream>

using namespace std;

char graph[1001][1001];
bool visited[1001][1001];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;

void DFS(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x == N) {
			cout << "YES";
			exit(0);
		}

		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && !visited[next_x][next_y] && graph[next_x][next_y] == '0') {
			DFS(next_x,next_y);
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[0][j] == '0' && !visited[i][j]) {
				DFS(0, j);
			}
		}
	}

	cout << "NO";
	return 0;
}