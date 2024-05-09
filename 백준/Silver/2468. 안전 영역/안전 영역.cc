//boj2468번_안전 영역_그래프

#include<iostream>

using namespace std;

int graph[101][101];
bool visited[101][101];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N;

void DFS(int x, int y, int height) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && !visited[next_x][next_y] && graph[next_x][next_y] > height) {
			DFS(next_x, next_y, height);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	int max = -1;

	for (int h = 0; h < 101; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = false;
			}
		}

		int count = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j] > h && !visited[i][j]) {
					DFS(i, j, h);
					count++;
				}
			}
		}
		max = std::max(max, count);
	}

	cout << max;
}