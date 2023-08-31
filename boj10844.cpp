//boj10844번_쉬운 계단 수_dp

#include <iostream>

using namespace std;

long long dp[101][10];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][1] % 1000000000;
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][8] % 1000000000;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
		}
	}

	long long result = 0;

	for (int i = 0; i <= 9; i++) {
		result += dp[N][i] % 1000000000;
	}

	cout << result % 1000000000;
}
//길이가 i이고 계단수가 0으로 끝날경우 바로 전의 수가 1일 수 밖에없고, 길이가 i고 계단수가 9로 끝날경우 바로 전의 수가 8일수 밖에없다.
//그리고 2~8은 앞뒤로 2개씩 가능하므로 j-1, j+1의 개수를 더하면 된다.