//boj16928번_뱀과 사다리 게임_그래프

#include<iostream>
#include<queue>

using namespace std;

int graph[101];
bool visited[101];

void BFS(int V) {
	queue<pair<int, int>> q;
	q.push({ V,0 });

	while (!q.empty()) {
		int cur_v = q.front().first;
		int count = q.front().second;
		visited[cur_v] = true;

		q.pop();

		for (int i = 1; i <= 6; i++) {
			int next_v = cur_v + i;

			if (next_v == 100) {
				cout << count + 1;
				exit(0);
			}

			if (next_v < 100) {
				if (graph[next_v] != 0) {
					next_v = graph[next_v];
				}

				if (!visited[next_v]) {
					q.push({ next_v,count + 1 });
				}
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int v1, v2;
		cin >> v1 >> v2;

		graph[v1] = v2;
	}

	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;

		graph[v1] = v2;
	}

	BFS(1);

	return 0;
}