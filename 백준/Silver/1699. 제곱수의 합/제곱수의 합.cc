//boj1699번_제곱수의 합_dp

#include<iostream>

using namespace std;

int dp[100001];

int main() {
	int N;
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= N; i++) {
		dp[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - (j * j)] + 1);
		}
	}
	
	cout << dp[N];

	return 0;
}