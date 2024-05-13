//boj14889번_스타트와 링크_브루트포스

#include<iostream>
#include<cmath>

using namespace std;

int N;
int arr[21][21];
bool visited[21];
int result = 9999999;

void DFS(int people_num, int v) {
	if (people_num == N / 2) {
		int start = 0;
		int link = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i] && visited[j]) {
					start += arr[i][j];
				}
				else if (!visited[i] && !visited[j]) {
					link += arr[i][j];
				}
			}
		}
		result = min(result, abs(start-link));
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i] && v < i) {
			visited[i] = true;
			DFS(people_num + 1, i);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	DFS(0, -1);

	cout << result;

	return 0;
}