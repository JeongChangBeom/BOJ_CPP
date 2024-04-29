//boj12865번_평범한 배낭_dp

#include<iostream>
#include<vector>

using namespace std;

int dp[101][100001];

struct thing {
	int W, V;
};

int main() {
	int N, K;
	cin >> N >> K;

	vector<thing> v;

	thing t;
	t.W = 0;
	t.V = 0;

	v.push_back(t);

	for (int i = 1; i <= N; i++) {
		thing x;
		cin >> x.W >> x.V;

		v.push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			int weight = v[i].W;
			int value = v[i].V;

			if (weight > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
			}
		}
	}
	cout << dp[N][K];
	
	return 0;
}