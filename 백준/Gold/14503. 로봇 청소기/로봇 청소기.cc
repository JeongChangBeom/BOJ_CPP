//boj14503번_로봇청소기_그래프

#include<iostream>

using namespace std;

int graph[52][52];
bool visited[52][52];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int result = 0;

int N, M;

void DFS(int x, int y, int dir) {
	if (visited[x][y] == false) {
		result++;
	}

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int next_dir = (dir + 3 - i) % 4;

		int next_x = x + dx[next_dir];
		int next_y = y + dy[next_dir];

		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && graph[next_x][next_y] == 0 && !visited[next_x][next_y]) {
			DFS(next_x, next_y, next_dir);
		}
	}

	int next_dir = (dir + 2) % 4;

	int next_x = x + dx[next_dir];
	int next_y = y + dy[next_dir];

	if (graph[next_x][next_y] == 1) {
		cout << result;
		exit(0);
	}

	DFS(next_x, next_y, dir);
}

int main() {
	cin >> N >> M;

	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	DFS(r, c, d);

	cout << result;

	return 0;
}