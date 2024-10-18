//boj15651번_N과 M (3)_백트래킹

#include <iostream>

using namespace std;

int arr[9];
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
		arr[V] = i;
		DFS(V + 1);
	}
}

int main() {
	cin >> N >> M;
	DFS(0);

	return 0;
}