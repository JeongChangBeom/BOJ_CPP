//boj15656번_N과 M (7)_백트래킹

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[9];
int arr2[9];

int N, M;

void DFS(int x, int y) {
	if (y == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		arr[y] = arr2[i];
		DFS(i + 1, y + 1);
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