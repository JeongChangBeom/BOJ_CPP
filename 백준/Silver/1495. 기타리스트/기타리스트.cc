//boj1495번_기타리스트_dp

#include<iostream>

using namespace std;

bool dp[51][1001];
int v[51];

int main() {
	int N, S, M;
	cin >> N >> S >> M;

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	dp[0][S] = true;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j]) {
				if (j + v[i] <= M) {
					dp[i][j + v[i]] = true;
				}
				if (j - v[i] >= 0) {
					dp[i][j - v[i]] = true;
				}
			}
		}
	}

	for (int i = M; i >= 0; i--) {
		if (dp[N][i]) {
			cout << i;
			return 0;
		}
	}

	cout << -1;

	return 0;
}