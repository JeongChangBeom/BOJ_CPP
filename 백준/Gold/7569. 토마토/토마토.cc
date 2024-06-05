//boj7569번_토마토_그래프

#include<iostream>
#include<queue>

using namespace std;

int graph[101][101][101];

queue<pair<pair<int, int>, int>> q;

int dx[6] = { 0,0,0,0,-1,1 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 1,0,-1,0,0,0 };

int N, M, H;

void BFS() {
	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int next_x = a + dx[i];
			int next_y = b + dy[i];
			int next_z = c + dz[i];

			if (next_x >= 0 && next_x < H && next_y >= 0 && next_y < M && next_z >= 0 && next_z < N && graph[next_x][next_y][next_z] == 0) {
				q.push({ {next_x,next_y},next_z });
				graph[next_x][next_y][next_z] = graph[a][b][c] + 1;
			}
		}
	}
}

int main() {
	cin >> N >> M >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				cin >> graph[i][j][k];
				if (graph[i][j][k] == 1) {
					q.push({ { i,j }, k });
				}
			}
		}
	}

	BFS();

	int result = 0;
	bool check = false;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (graph[i][j][k] == 0) {
					check = true;
				}
				result = max(result, graph[i][j][k]);
			}
		}
	}

	if (check) {
		cout << -1;
	}
	else {
		cout << result - 1;
	}

	return 0;
}