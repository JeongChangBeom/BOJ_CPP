//boj18352번_특정 거리의 도시 찾기_그래프

#include<iostream>
#include<queue>

using namespace std;

vector<int> graph[300001];
int dist[300001];
bool visited[300001];
int cnt = 0;

void BFS(int V) {
	visited[V] = true;
	queue<int> q;
	q.push(V);

	while (!q.empty()) {
		V = q.front();
		q.pop();

		for (int i = 0; i < graph[V].size(); i++) {
			int num = graph[V][i];

			if (!visited[num]) {
				dist[num] = dist[V] + 1;
				visited[num] = true;
				q.push(num);
			}
		}
	}
}

int main() {
	int N, M, K, X;
	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++) {
		int V1, V2;
		cin >> V1 >> V2;

		graph[V1].push_back(V2);
	}

	BFS(X);

	bool check = false;

	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			check = true;
			cout << i << '\n';
		}
	}

	if (!check) {
		cout << -1;
	}

	return 0;
}