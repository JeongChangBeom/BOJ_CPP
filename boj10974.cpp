//boj10974번_모든 순열_백트래킹

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[9];

bool visited[9];

int N;

void DFS(int x, int y) {
	if (y == N) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[y] = i + 1;
			DFS(i + 1, y + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N;

	DFS(1, 0);
}
//백트래킹 문제. 최근에 풀었던 N과M 시리즈중에 비슷한 문제가 있어 쉽게 풀 수 있었다.