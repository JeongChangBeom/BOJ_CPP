//boj18111번_마인크래프트_브루트포스

#include<iostream>

using namespace std;

int arr[501][501];

int main() {
	int N, M, B;
	int mintime = 2147483647;
	int height = -1;
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int h = 0; h <= 256; h++) {
		int add = 0;
		int sub = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] - h > 0) {
					sub += arr[i][j] - h;
				}
				else if (arr[i][j] - h < 0) {
					add -= arr[i][j] - h;
				}
			}
		}

		if (sub + B >= add) {
			int time = 2 * sub + add;
			if (mintime >= time) {
				mintime = time;
				height = h;
			}
		}
	}

	cout << mintime << " " << height;
}