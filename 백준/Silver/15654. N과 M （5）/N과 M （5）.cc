//boj15654번_N과 M (5)_백트래킹

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[9];
int result[9];

bool visited[9];

int N, M;

void DFS(int v) {
	if (v == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[v] = result[i];
			DFS(v + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> result[i];
	}

	sort(result, result + N);

	DFS(0);
}