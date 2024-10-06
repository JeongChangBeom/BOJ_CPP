//boj11060번_점프 점프_그래프

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int graph[1001];
bool visited[1001];

int N;

void BFS() {
	visited[1] = true;

	queue<pair<int, int>> q;
	q.push({ 1,0 });

	while (!q.empty()) {
		int v = q.front().first;
		int count = q.front().second;
		q.pop();

		if (v == N) {
			cout << count;
			exit(0);
		}

		for (int i = 1; i <= graph[v]; i++) {
			if (!visited[v + i]) {
				visited[v + i] = true;
				q.push({ v + i,count + 1 });
			}
		}
	}
	if (!visited[N]) {
		cout << -1;
		exit(0);
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> graph[i];
	}

	BFS();

	return 0;
}