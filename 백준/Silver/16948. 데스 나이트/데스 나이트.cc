//boj16948번_데스 나이트_그래프

#include<iostream>
#include<queue>

using namespace std;

int dist[201][201];
int visited[201][201];

int dx[6] = { -2,-2,0,0,2,2 };
int dy[6] = { -1,1,-2,2,-1,1 };

int N;
int r1, c1, r2, c2;

void BFS(int x, int y) {
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		if (a == r2 && b == c2) {
			cout << dist[a][b] << '\n';
			return;
		}

		for (int i = 0; i < 6; i++) {
			int next_x = a + dx[i];
			int next_y = b + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && !visited[next_x][next_y]) {
				visited[next_x][next_y] = true;
				q.push({ next_x,next_y });
				dist[next_x][next_y] = dist[a][b] + 1;
			}
		}
	}
	cout << -1;
}

int main() {
	cin >> N;
	cin >> r1 >> c1 >> r2 >> c2;

	BFS(r1, c1);

	for (int i = 0; i < 201; i++) {
		for (int j = 0; j < 201; j++) {
			dist[i][j] = 0;
			visited[i][j] = false;
		}
	}

	return 0;
}