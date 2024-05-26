//boj11403번_경로 찾기_그래프

#include<iostream>

using namespace std;

int graph[101][101];
bool visited[101];

int N;

void DFS(int v) {
	for (int i = 0; i < N; i++) {
		if (!visited[i] && graph[v][i] == 1) {
			visited[i] = true;
			DFS(i);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 101; j++) {
			visited[j] = false;
		}
		DFS(i);
		for (int j = 0; j < N; j++) {
			cout << visited[j] << " ";
		}
		cout << '\n';
	}

	return 0;
}
