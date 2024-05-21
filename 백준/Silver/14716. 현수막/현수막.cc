//boj14716번_현수막_그래프

#include<iostream>

using namespace std;

int graph[251][251];
int visited[251][251];

int dx[8] = { 1,0,-1,0,1,-1,1,-1 };
int dy[8] = { 0,1,0,-1,1,-1,-1,1 };

int M, N;

void DFS(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N && !visited[next_x][next_y] && graph[next_x][next_y] == 1) {
			DFS(next_x, next_y);
		}
	}
}

int main() {
	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	int result = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && graph[i][j] == 1) {
				DFS(i, j);
				result++;
			}
		}
	}

	cout << result;

	return 0;
}