//boj2293번_동전 1_dp

#include <iostream>
#include <algorithm>

using namespace std;

int dp[10001];
int coin[101];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}

	cout << dp[k];

	return 0;
}
//i원을 사용해서 j원을 만드려면 j - coin[i]의 누적합을 구하면되므로 점화식은 dp[j] = dp[j] + dp[j - coin[i]]가 된다