//boj2583번_영역 구하기_그래프

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool graph[101][101];
bool visited[101][101];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int M, N, K;

int square_size = 0;

void DFS(int x, int y) {
	visited[x][y] = true;
	square_size++;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N && !visited[next_x][next_y] && !graph[next_x][next_y]) {
			DFS(next_x, next_y);
		}
	}
}

int main() {
	cin >> M >> N >> K;

	for (int t = 0; t < K; t++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				graph[i][j] = true;
			}
		}
	}

	vector<int> result;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && !graph[i][j]) {
				DFS(i, j);
				result.push_back(square_size);
				square_size = 0;
			}
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << '\n';

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}