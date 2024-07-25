//boj2589번_보물섬_그래프

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

char graph[51][51];
bool visited[51][51];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;

int result = 0;

void BFS(int x, int y) {
	visited[x][y] = true;

	queue<pair<pair<int, int>, int>> q;
	q.push({ { x,y },0 });

	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;

		int count = q.front().second;

		q.pop();

		result = max(result, count);

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && graph[next_x][next_y] == 'L' && !visited[next_x][next_y]) {
				visited[next_x][next_y] = true;
				q.push({ { next_x,next_y }, count + 1 });
			}
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
			if (graph[i][j] == 'L') {
				for (int a = 0; a < N; a++) {
					for (int b = 0; b < M; b++) {
						visited[a][b] = false;
					}
				}
				BFS(i, j);
			}
		}
	}
	cout << result;

	return 0;
}