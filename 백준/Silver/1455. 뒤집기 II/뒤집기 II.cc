//boj1455번_뒤집기 II_그리디 알고리즘

#include<iostream>

using namespace std;

int arr[101][101];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	int result = 0;

	for (int i = N; i > 0; i--) {
		for (int j = M; j > 0; j--) {
			if (arr[i][j] == 1) {
				for (int x = 1; x <= i; x++) {
					for (int y = 1; y <= j; y++) {
						if (arr[x][y] == 1) {
							arr[x][y] = false;
						}
						else {
							arr[x][y] = true;
						}
					}
				}
				result++;
			}
		}
	}

	cout << result;

	return 0;
}