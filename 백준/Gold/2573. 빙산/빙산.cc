//boj2573번_빙산_그래프

#include<iostream>

using namespace std;

int graph[301][301];
int melt[301][301];
bool visited[301][301];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;

int year = 0;

void DFS(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && !visited[next_x][next_y] && graph[next_x][next_y] != 0) {
			DFS(next_x, next_y);
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

	while (true) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = false;
				melt[i][j] = 0;
			}
		}

		int cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && graph[i][j] != 0) {
					DFS(i, j);
					cnt++;
				}
			}
		}

		if (cnt >= 2) {
			cout << year;
			return 0;
		}

		year++;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < 4; k++) {
					int melt_x = i + dx[k];
					int melt_y = j + dy[k];

					if (melt_x >= 0 && melt_x < N && melt_y >= 0 && melt_y < M && graph[melt_x][melt_y] == 0) {
						melt[i][j] += 1;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				graph[i][j] -= melt[i][j];
				if (graph[i][j] < 0) {
					graph[i][j] = 0;
				}
			}
		}

		bool check = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] != 0) {
					check = true;
				}
			}
		}

		if (!check) {
			cout << 0;
			return 0;
		}
	}
}