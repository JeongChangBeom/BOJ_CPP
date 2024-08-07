//boj14500_테트로미노_브루트포스 알고리즘

#include<iostream>

using namespace std;

int graph[501][501];
bool visited[501][501];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;

int result;

void DFS(int x, int y, int cnt, int sum) {
	visited[x][y] = true;
	cnt++;

	if (cnt == 4) {
		result = max(result, sum);
		visited[x][y] = false;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && !visited[next_x][next_y]) {
			DFS(next_x, next_y, cnt, sum + graph[next_x][next_y]);
		}
	}
	visited[x][y] = false;
}

void T_shape(int x, int y) {
	int T_sum;

	if (x - 1 >= 0 && x + 1 < N && y - 1 >= 0) {
		T_sum = graph[x][y] + graph[x - 1][y] + graph[x + 1][y] + graph[x][y - 1];
		result = max(result, T_sum);
	}
	if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < M) {
		T_sum = graph[x][y] + graph[x - 1][y] + graph[x][y - 1] + graph[x][y + 1];
		result = max(result, T_sum);
	}
	if (x - 1 >= 0 && x + 1 < N && y + 1 < M) {
		T_sum = graph[x][y] + graph[x - 1][y] + graph[x + 1][y] + graph[x][y + 1];
		result = max(result, T_sum);
	}
	if (x + 1 < N && y - 1 >= 0 && y + 1 < M) {
		T_sum = graph[x][y] + graph[x + 1][y] + graph[x][y - 1] + graph[x][y + 1];
		result = max(result, T_sum);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			DFS(i, j, 0, graph[i][j]);
			T_shape(i, j);
		}
	}

	cout << result;

	return 0;
}