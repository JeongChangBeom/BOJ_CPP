//boj2644번_촌수계산_그래프

#include<iostream>

using namespace std;

int graph[101][101];
bool visited[101];

int N;
int result = 0;

void DFS(int v, int end, int count) {
	visited[v] = true;

	if (v == end) {
		result = count;
	}

	for (int i = 1; i <= N; i++) {
		if (graph[v][i] == 1 && !visited[i]) {
			DFS(i, end, count + 1);
		}
	}
}

int main() {
	cin >> N;

	int a, b;
	cin >> a >> b;

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;

		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	DFS(a, b, 0);

	if (result == 0) {
		cout << "-1";
	}
	else {
		cout << result;
	}
}