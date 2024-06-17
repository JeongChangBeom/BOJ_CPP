//boj1080번_행렬_그리디 알고리즘

#include<iostream>

using namespace std;

int arr1[51][51];
int arr2[51][51];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr1[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr2[i][j]);
		}
	}

	int result = 0;

	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (arr1[i][j] != arr2[i][j]) {
				result++;
				for (int x = i; x < i + 3; x++) {
					for (int y = j; y < j + 3; y++) {
						if (arr1[x][y] == 0) {
							arr1[x][y] = 1;
						}
						else {
							arr1[x][y] = 0;
						}
					}
				}
			}
		}
	}
	
	bool check = true;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr1[i][j] != arr2[i][j]) {
				check = false;
			}
		}
	}

	if (check) {
		cout << result;
	}
	else {
		cout << -1;
	}
}