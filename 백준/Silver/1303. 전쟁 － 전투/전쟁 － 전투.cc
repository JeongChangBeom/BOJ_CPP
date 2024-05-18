//boj1303번_전쟁 - 전투_그래프

#include<iostream>

using namespace std;

char graph[101][101];
bool visited[101][101];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;

int num = 0;

void DFS(int x, int y) {
	visited[x][y] = true;
	num++;

	char team = graph[x][y];

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N && !visited[next_x][next_y] && graph[next_x][next_y] == team) {
			DFS(next_x, next_y);
		}
	}

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	int W_sum = 0;
	int B_sum = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				DFS(i, j);
				if (graph[i][j] == 'W') {
					W_sum += num * num;
				}
				else {
					B_sum += num * num;
				}
				num = 0;
			}
		}
	}

	cout << W_sum << " " << B_sum;

	return 0;
}