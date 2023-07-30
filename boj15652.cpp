//boj15652번_N과 M (4)_백트래킹

#include <iostream>

using namespace std;

int arr[9];
bool visited[9];
int N, M;

void DFS(int x, int y) {
	if (y == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = x; i <= N; i++) {
		visited[i] = true;
		arr[y] = i;
		DFS(i, y + 1);
		visited[i] = false;
	}
}

int main() {
	cin >> N >> M;
	DFS(1, 0);

	return 0;
}