//boj7562_나이트의 이동_그래프

#include<iostream>
#include<queue>

using namespace std;

int dist[301][301];
bool visited[301][301];

int dx[8] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

int I;
int knight_x, knight_y;
int goal_x, goal_y;

void BFS(int x, int y) {
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		if (a == goal_x && b == goal_y) {
			cout << dist[a][b] << '\n';
			break;
		}

		for (int i = 0; i < 8; i++) {
			int next_x = a + dx[i];
			int next_y = b + dy[i];

			if (next_x >= 0 && next_x < I && next_y >= 0 && next_y < I && !visited[next_x][next_y]) {
				visited[next_x][next_y] = true;
				q.push({ next_x,next_y });
				dist[next_x][next_y] = dist[a][b] + 1;
			}
		}
	}

}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> I;

		cin >> knight_x >> knight_y;
		cin >> goal_x >> goal_y;

		BFS(knight_x, knight_y);

		for (int i = 0; i < 301; i++) {
			for (int j = 0; j < 301; j++) {
				dist[i][j] = 0;
				visited[i][j] = false;
			}
		}
	}
}