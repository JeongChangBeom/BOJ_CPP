//boj15649_N과 M (1)_백트래킹

#include <iostream>
#include <vector>

using namespace std;

int arr[9];
bool visited[9];
int N, M;

void DFS(int V) {
	if (V == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			arr[V] = i;
			DFS(V + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	DFS(0);

	return 0;
}