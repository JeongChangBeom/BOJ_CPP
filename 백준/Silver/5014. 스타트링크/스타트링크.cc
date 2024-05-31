//boj5014번_스타트링크_그래프

#include<iostream>
#include<queue>

using namespace std;

int visited[1000001];
int dist[1000001];
int dx[2];

int F, S, G, U, D;

void BFS(int v) {
	visited[v] = true;
	queue<int> q;
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		q.pop();

		if (v == G) {
			cout << dist[v];
			return;
		}

		for (int i = 0; i < 2; i++) {
			int next_v = v + dx[i];

			if (next_v > 0 && next_v <= F && !visited[next_v]) {
				visited[next_v] = true;
				q.push(next_v);
				dist[next_v] = dist[v] + 1;
			}
		}
	}

	cout << "use the stairs";
}

int main() {
	cin >> F >> S >> G >> U >> D;

	dx[0] = U;
	dx[1] = -D;

	BFS(S);

	return 0;
}