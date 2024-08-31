//boj16926번_배열 돌리기 1_구현

#include<iostream>

using namespace std;

int N, M, R;

int graph[301][301];

int dx[4] = {0,1,0,-1};
int dy[4] = { 1,0,-1,0 };

void rotate() {
	for (int i = 0; i < min(N, M) / 2; i++) {
		int x = i;
		int y = i;
		int rot = 0;

		int start = graph[i][i];

		while (rot < 4) {
			int prev_x = x + dx[rot];
			int prev_y = y + dy[rot];

			if (prev_x >= i && prev_x < N - i && prev_y >= i && prev_y < M - i) {
				graph[x][y] = graph[prev_x][prev_y];
				x = prev_x;
				y = prev_y;
			}
			else {
				rot++;
			}
		}
		graph[i + 1][i] = start;
	}
}

int main() {
	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		rotate();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << graph[i][j] << " ";
		}
		cout << '\n';
	}
}