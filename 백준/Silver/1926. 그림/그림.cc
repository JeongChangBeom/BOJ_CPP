//boj1926번_그림_그래프

#include<iostream>

using namespace std;

bool graph[501][501];
bool visited[501][501];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int picture_size = 0;

int n, m;

void DFS(int x, int y) {
	visited[x][y] = true;
	picture_size++;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && !visited[next_x][next_y] && graph[next_x][next_y]) {
			DFS(next_x, next_y);
		}
	}
	
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	int max_size = 0;
	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && graph[i][j]) {
				DFS(i, j);
				max_size = max(max_size, picture_size);
				picture_size = 0;
				count++;
			}
		}
	}

	cout << count << '\n' << max_size;

	return 0;
}