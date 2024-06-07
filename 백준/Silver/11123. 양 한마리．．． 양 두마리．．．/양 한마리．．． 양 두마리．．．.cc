//boj11123번_양 한마리... 양 두마리..._그래프

#include<iostream>

using namespace std;

char graph[101][101];
bool visited[101][101];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int H, W;
int result = 0;

void DFS(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < H && next_y >= 0 && next_y < W && !visited[next_x][next_y] && graph[next_x][next_y] == '#') {
			DFS(next_x, next_y);
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		result = 0;

		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				graph[i][j] = 0;
				visited[i][j] = false;
			}
		}

		cin >> H >> W;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> graph[i][j];
			}
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (!visited[i][j] && graph[i][j] == '#') {
					DFS(i, j);
					result++;
				}
			}
		}

		cout << result << '\n';
	}
}