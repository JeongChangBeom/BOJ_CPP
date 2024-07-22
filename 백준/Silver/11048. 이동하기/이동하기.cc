//boj11048번_이동하기_dp

#include<iostream>

using namespace std;

int arr[1001][1001];
int dp[1001][1001];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int num;
			cin >> num;

			arr[i][j] = num;
			dp[i][j] = num;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = arr[i][j] + max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]));
		}
	}

	cout << dp[N][M];
}