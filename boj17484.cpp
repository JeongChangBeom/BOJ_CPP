//boj17484번_진우의 달 여행(small)_dfs

#include<iostream>

using namespace std;

int graph[7][7];
int dir[3] = { -1,0,1 };
bool visited[7];
int N, M;
int result = 999999;

int DFS(int move, int x, int dirY) {
	int min = 999999;

	if (move == N) {
		return 0;
	}

	for (int i = 0; i < 3; i++) {
		if (dirY == dir[i]) {
			continue;
		}

		if (x + dir[i] < 0 || x + dir[i] >= M) {
			continue;
		}

		min = std::min(min, DFS(move + 1, x + dir[i], dir[i]) + graph[move][x]);
	}
	return min;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		result = min(result, DFS(0, i, -2));
	}

	cout << result << '\n';
}
//dfs문제.
//알고리즘 분류에는 브루트포스,dp로 나와있지만 문제를 보고 dfs가 떠올라서 dfs로 구현했다.