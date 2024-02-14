//boj2566번_최댓값_구현

#include<iostream>

using namespace std;

int arr[10][10];

int main() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
		}
	}

	int max = -999;
	int result_i = -999;
	int result_j = -999;


	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (max < arr[i][j]) {
				max = arr[i][j];
				result_i = i;
				result_j = j;
			}
		}
	}

	cout << max << '\n' << result_i << ' ' << result_j;
}