//boj9372번_상근이의 여행_그래프

#include<iostream>

using namespace std;

int graph[1001];
bool visited[1001];
int N, M;
int cnt;

void DFS(int V) {
	visited[V] = true;
	cnt++;

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int i = 0; i < 1001; i++) {
			graph[i] = 0;
			visited[i] = false;
		}

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;

			graph[a] = b;
			graph[b] = a;
		}

		cnt = 0;
		DFS(1);
		cout << cnt - 1 << '\n';
	}
}