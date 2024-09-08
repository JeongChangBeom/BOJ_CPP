//boj16194번_카드 구매하기 2_dp

#include <iostream>

using namespace std;

int dp[1001];
int card[1001];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}

	dp[1] = card[1];

	for (int i = 2; i <= N; i++) {
		dp[i] = card[i];
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j] + card[j]);
		}
	}
	cout << dp[N];

	return 0;
}