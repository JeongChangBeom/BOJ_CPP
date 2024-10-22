//boj2502번_떡 먹는 호랑이_dp

#include<iostream>

using namespace std;

int dp_a[31];
int dp_b[31];

int main() {
	int D, K;
	cin >> D >> K;

	dp_a[1] = 1;
	dp_a[2] = 0;
	dp_a[3] = 1;

	dp_b[1] = 0;
	dp_b[2] = 1;
	dp_b[3] = 1;

	for (int i = 3; i <= D; i++) {
		dp_a[i] = dp_a[i - 2] + dp_a[i - 1];
		dp_b[i] = dp_b[i - 2] + dp_b[i - 1];
	}

	for (int i = 1; i < 100000; i++) {
		for (int j = 1; j < 100000; j++) {
			if (dp_a[D] * i + dp_b[D] * j == K) {
				cout << i << '\n';
				cout << j;

				return 0;
			}
		}
	}

	return 0;
}