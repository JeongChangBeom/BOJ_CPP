//boj9251번_LCS_dp

#include<iostream>

int dp[1001][1001];

using namespace std;

int main() {
	string a, b;

	cin >> a;
	cin >> b;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[a.size()][b.size()];

	return 0;
}