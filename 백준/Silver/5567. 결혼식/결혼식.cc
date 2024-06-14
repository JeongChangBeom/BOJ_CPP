//boj5567번_결혼식_그래프

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> graph[510];
bool visited[501];

int n, m;

void DFS(int V, int count) {
	visited[V] = true;

	if (count == 2) {
		return;
	}

	for (int i = 0; i < graph[V].size(); i++) {
		int next_V = graph[V][i];
		visited[next_V] = true;
		DFS(next_V, count + 1);
	}
}

int main() {
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(1,0);

	int result = 0;

	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			result++;
		}
	}

	cout << result - 1;

	return 0;
}