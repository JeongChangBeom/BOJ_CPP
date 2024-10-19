//boj15652번_N과 M (4)_백트래킹

#include <iostream>

using namespace std;

int arr[9];
int N, M;

void DFS(int v, int num) {
	if (v == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = num; i <= N; i++) {
		arr[v] = i;
		DFS(v + 1, i);
	}
}

int main() {
	cin >> N >> M;
	DFS(0, 1);

	return 0;
}