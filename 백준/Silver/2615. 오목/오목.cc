//boj2615번_오목_브루트포스 알고리즘

#include<iostream>

using namespace std;

int graph[20][20];
bool visited[20][20][5];

int dx[4] = { -1,0,1,1 };
int dy[4] = { 1,1,1,0 };

int cnt;

void DFS(int x, int y, int dir) {
	visited[x][y][dir] = true;

	int next_x = x + dx[dir];
	int next_y = y + dy[dir];

	if (next_x > 0 && next_x <= 19 && next_y > 0 && next_y <= 19) {
		if (graph[x][y] == graph[next_x][next_y]) {
			cnt++;
			DFS(next_x, next_y, dir);
		}
	}
}

int main() {
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			if (graph[i][j] == 1 || graph[i][j] == 2) {
				for (int k = 0; k < 4; k++) {
					if (!visited[i][j][k]) {
						cnt = 1;
						DFS(i, j, k);

						int next_i = i + 1;
						int next_j = j - 1;

						if (k == 0) {
							DFS(i + 1, j - 1, k);
						}

						if (cnt == 5) {

							cout << graph[i][j] << '\n';
							cout << i << " " << j;

							return 0;
						}
					}
				}
			}
		}
	}

	cout << 0;

	return 0;
}