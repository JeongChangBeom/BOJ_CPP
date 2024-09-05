//boj1245번_농장 관리_그래프

#include<iostream>

using namespace std;

int graph[101][71];
bool visited[101][71];

int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

int N, M;

int cnt = 0;

bool check;

void DFS(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && graph[x][y] < graph[next_x][next_y]) {
			check = false;
		}

		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && !visited[next_x][next_y]) {
			if (graph[next_x][next_y] == graph[x][y]) {
				DFS(next_x, next_y);
			}
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
			if (!visited[i][j] && graph[i][j] != 0) {
				check = true;

				DFS(i, j);

				if (check) {
					cnt++;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}