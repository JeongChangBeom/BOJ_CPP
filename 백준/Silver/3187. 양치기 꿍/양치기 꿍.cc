//boj3187번_양치기 꿍_그래프

#include<iostream>

using namespace std;

char graph[251][251];
bool visited[251][251];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int R, C;

int sheep = 0;
int wolf = 0;
int sheep_result = 0;
int wolf_result = 0;

void DFS(int x, int y) {
	visited[x][y] = true;

	if (graph[x][y] == 'v') {
		wolf++;
	}
	else if (graph[x][y] == 'k') {
		sheep++;
	}

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C && graph[next_x][next_y] != '#' && !visited[next_x][next_y]) {
			DFS(next_x, next_y);
		}
	}
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if ((graph[i][j] == 'v' || graph[i][j] == 'k') && !visited[i][j]) {
				wolf = 0;
				sheep = 0;

				DFS(i, j);

				if (wolf < sheep) {
					sheep_result += sheep;
				}
				else if (sheep <= wolf) {
					wolf_result += wolf;
				}
			}
		}
	}

	cout << sheep_result << " " << wolf_result;

	return 0;
}