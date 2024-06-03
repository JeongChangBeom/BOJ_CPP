//boj21736번_헌내기는 친구가 필요해_그래프

#include<iostream>

using namespace std;

char graph[601][601];
bool visited[601][601];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;

int result = 0;

void DFS(int x, int y) {
	if (graph[x][y] == 'P') {
		result++;
	}

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && !visited[next_x][next_y] && graph[next_x][next_y] != 'X') {
			DFS(next_x,next_y);
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 'I') {
				DFS(i, j);
			}
		}
	}
	
	if (result == 0) {
		cout << "TT";
	}
	else {
		cout << result;
	}

	return 0;
}