//boj11057번_오르막 수_dp

#include <iostream>

using namespace std;

int dp[1001][10];
int tile[1001];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < 10; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
		}
	}

	int result = 0;

	for (int i = 0; i < 10; i++) {
		result += dp[N][i] % 10007;
	}

	cout << result % 10007;
}
//2차원 배열dp의 열(i)의 길이의 행(j)으로 끝나는 수의 개수를 저장해주면서 해결했다.