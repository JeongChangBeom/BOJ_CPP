//boj3184번_양_그래프

#include<iostream>

using namespace std;

char graph[251][251];
bool visited[251][251];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int R, C;

int wolf = 0;
int sheep = 0;

void DFS(int x, int y) {
	visited[x][y] = true;

	if (graph[x][y] == 'v') {
		wolf++;
	}
	else if (graph[x][y] == 'o') {
		sheep++;
	}

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		
		if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C && !visited[next_x][next_y] && graph[next_x][next_y] != '#') {
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

	int wolf_sum = 0;
	int sheep_sum = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visited[i][j] && graph[i][j] != '#') {
				DFS(i, j);
				if (sheep > wolf) {
					wolf = 0;
				}
				else {
					sheep = 0;
				}
				wolf_sum += wolf;
				sheep_sum += sheep;

				wolf = 0;
				sheep = 0;
			}
		}
	}

	cout << sheep_sum << " " << wolf_sum;

	return 0;
}