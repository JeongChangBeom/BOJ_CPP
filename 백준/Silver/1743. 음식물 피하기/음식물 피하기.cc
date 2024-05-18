//boj1743번_음식물 피하기_그래프

#include<iostream>
#include<vector>

using namespace std;

bool graph[105][105];
bool visited[105][105];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int cnt = 0;

int N, M, K;

void DFS(int x, int y) {
	visited[x][y] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		
		if (next_x > 0 && next_x <= N && next_y > 0 && next_y <= M && !visited[next_x][next_y] && graph[next_x][next_y]) {
			DFS(next_x, next_y);
		}
	}
}

int main() {
	cin >> N >> M >> K;

	int max = 0;

	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;

		graph[x][y] = true;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visited[i][j] && graph[i][j]) {
				DFS(i, j);
				max = std::max(max, cnt);
				cnt = 0;
			}
		}
	}

	cout << max;

	return 0;
}