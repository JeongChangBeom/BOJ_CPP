//boj15654번_N과 M (5)_백트래킹

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[9];
int arr2[9];

bool visited[9];

int N, M;

void DFS(int x, int y) {
	if (y == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[y] = arr2[i - 1];
			DFS(i+1, y + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr2[i];
	}

	sort(arr2, arr2 + N);

	DFS(1, 0);
}