//boj9657번_돌 게임 3_DP

#include<iostream>

using namespace std;

int dp[1001];

int main() {
	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;

	for (int i = 5; i <= N; i++) {
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0) {
			dp[i] = 1;
		}
		else {
			dp[i] = 0;
		}
	}

	if (dp[N] == 1) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}

	return 0;
}