//boj9466_텀 프로젝트_그래프

#include<iostream>
#include<set>

using namespace std;

int graph[100001];
bool visited[100001];
bool group[100001];

int result;

void DFS(int V) {
	visited[V] = true;

	if (!visited[graph[V]]) {
		DFS(graph[V]);
	}
	else {
		if (!group[graph[V]]) {
			for (int i = graph[V]; i != V; i = graph[i]) {
				result--;
			}
			result--;
		}
	}
	group[V] = true;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 100001; i++) {
			visited[i] = false;
		}
		for (int i = 0; i < 100001; i++) {
			group[i] = false;
		}

		int N;
		cin >> N;

		result = N;

		for (int i = 1; i <= N; i++) {
			cin >> graph[i];
		}

		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				DFS(i);
			}
		}
		cout << result << '\n';
	}
	return 0;
}