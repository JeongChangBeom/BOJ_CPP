//boj3085번_사탕 게임_브루트포스

#include<iostream>

using namespace std;

char arr[51][51];

int N;
int result = 0;

void check_width() {
	for (int x = 0; x < N; x++) {
		int width = 1;
		for (int y = 0; y < N - 1; y++) {
			if (arr[x][y] == arr[x][y + 1]) {
				width++;
			}
			else {
				result = max(result, width);
				width = 1;
			}
		}
		result = max(result, width);
	}
}

void check_height() {
	for (int x = 0; x < N; x++) {
		int height = 1;
		for (int y = 0; y < N - 1; y++) {
			if (arr[y][x] == arr[y + 1][x]) {
				height++;
			}
			else {
				result = max(result, height);
				height = 1;
			}
		}
		result = max(result, height);
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			swap(arr[i][j], arr[i][j + 1]);

			check_width();
			check_height();

			swap(arr[i][j], arr[i][j + 1]);

			swap(arr[j][i], arr[j + 1][i]);

			check_width();
			check_height();

			swap(arr[j][i], arr[j + 1][i]);
		}
	}
	cout << result;

	return 0;
}