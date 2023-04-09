//boj11724번_연결 요소의 개수_그래프

#include<iostream>

using namespace std;

int graph[1001][1001];
bool visited[1001];
int N, M;
int result;

void DFS(int V) {
	visited[V] = true;

	for (int i = 1; i <= N; i++) {
		if (graph[V][i] == 1 && visited[i] == false) {
			DFS(i);
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			result++;

			DFS(i);
		}
	}

	cout << result;
}
//주어진 그래프를 DFS를 통해 탐색하면서 연결요소를 세주기만 하면 되는 문제.