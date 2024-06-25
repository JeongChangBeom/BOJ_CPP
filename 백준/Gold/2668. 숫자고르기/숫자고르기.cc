//boj2668번_숫자고르기_그래프

#include<iostream>
#include<vector>

using namespace std;

int graph[101];
int visited[101];

vector<int> result;

void DFS(int V, int first_V) {
	if (visited[V]) {
		if (V == first_V) {
			result.push_back(V);
		}
		return;
	}

	visited[V] = true;
	DFS(graph[V], first_V);
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> graph[i];
	}

	for (int i = 1; i <= N; i++) {

		for (int j = 0; j < 101; j++) {
			visited[j] = false;
		}

		DFS(i, i);
	}

	cout << result.size() << '\n';

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}

	return 0;
}