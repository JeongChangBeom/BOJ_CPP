//boj16174번_점프왕 쩰리 (Large)_그래프

#include<iostream>

using namespace std;

int graph[65][65];
bool visited[65][65];

int dx[2] = { 1,0 };
int dy[2] = { 0,1 };

int N;

bool check = false;

void DFS(int x, int y) {
	visited[x][y] = true;

	if (graph[x][y] == -1) {
		check = true;
		return;
	}

	for (int i = 0; i < 2; i++) {
		int next_x = x + (dx[i] * graph[x][y]);
		int next_y = y + (dy[i] * graph[x][y]);
		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && !visited[next_x][next_y]) {
			DFS(next_x, next_y);
		}
	}

}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	DFS(0, 0);

	if (check) {
		cout << "HaruHaru";
	}
	else {
		cout << "Hing";
	}

	return 0;
}