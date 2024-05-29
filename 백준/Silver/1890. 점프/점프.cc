//boj1890번_점프_dp

#include<iostream>

using namespace std;

int graph[101][101];
long long dp[101][101];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 0) {
				continue;
			}

			if (dp[i][j] != 0) {
				if (i + graph[i][j] < N) {
					dp[i + graph[i][j]][j] += dp[i][j];
				}
				if (j + graph[i][j] < N) {
					dp[i][j + graph[i][j]] += dp[i][j];
				}
			}
		}
	}
	cout << dp[N - 1][N - 1];

	return 0;
}