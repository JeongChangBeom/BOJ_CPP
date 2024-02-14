//boj2563번_색종이_구현

#include<iostream>

using namespace std;

bool arr[101][101];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				arr[j][k] = true;
			}
		}
	}

	int result = 0;

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j]) {
				result++;
			}
		}
	}

	cout << result;
}