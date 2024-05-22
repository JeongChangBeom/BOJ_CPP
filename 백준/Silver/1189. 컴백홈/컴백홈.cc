//boj1189번_컴백홈_그래프

#include<iostream>

using namespace std;

char graph[6][6];
bool visited[6][6];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int R, C, K;

int result = 0;

void DFS(int x, int y, int count) {
	if (count == K && x == 0 && y == C - 1) {
		result++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C && !visited[next_x][next_y] && graph[next_x][next_y] != 'T') {
			visited[next_x][next_y] = true;
			DFS(next_x, next_y, count + 1);
			visited[next_x][next_y] = false;
		}
	}
}

int main() {
	cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> graph[i][j];
		}
	}

	visited[R - 1][0] = true;

	DFS(R - 1, 0, 1);

	cout << result;

	return 0;
}