//boj12852번_1로 만들기 2_dp

#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int main() {
	int N;
	cin >> N;

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}

		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	cout << dp[N] << endl;

	while (true) {
		cout << N << " ";

		if (N == 1) {
			return 0;
		}

		if (N % 2 == 0 && dp[N] == dp[N / 2] + 1) {
			N /= 2;
		}
		else if (N % 3 == 0 && dp[N] == dp[N / 3] + 1) {
			N /= 3;
		}
		else if (dp[N] == dp[N - 1] + 1) {
			N--;
		}
	}

	return 0;
}