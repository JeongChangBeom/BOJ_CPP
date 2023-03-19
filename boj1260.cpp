//boj1260번_DFS와 BFS_그래프

#include <iostream>
#include <queue>

using namespace std;

int graph[1001][1001];
bool visited[1001];
int N, M, V;

void DFS(int V) {
	cout << V << " ";

	visited[V] = true;

	for (int i = 1; i <= N; i++) {
		if (graph[V][i] == 1 && visited[i] == false) {
			DFS(i);
		}
	}
}

void BFS(int V) {
	cout << V << " ";

	visited[V] = true;

	queue<int> q;
	q.push(V);
	while (q.empty() == false) {
		V = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (graph[V][i] == 1 && visited[i] == false) {
				visited[i] = true;
				q.push(i);
				cout << i << " ";
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;

	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	DFS(V);

	cout << endl;

	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}

	BFS(V);


	return 0;
}
//DFS와 BFS의 구현문제 그래프의 기초이므로 둘다 잘 알아두자