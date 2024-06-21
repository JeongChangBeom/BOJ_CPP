//boj2294번_동전 2_dp

#include<iostream>
#include<vector>

using namespace std;

int dp[10001];

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v;

	v.push_back(0);

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 1; i <= K; i++) {
		dp[i] = 99999;
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = v[i]; j <= K; j++) {
			dp[j] = min(dp[j], dp[j - v[i]] + 1);
		}
	}

	if (dp[K] == 99999) {
		cout << -1;
	}
	else {
		cout << dp[K];
	}

	return 0;
}