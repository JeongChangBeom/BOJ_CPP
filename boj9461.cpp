//boj9461번_파도반 수열_dp

#include <iostream>

using namespace std;

long long dp[101];

int main() {
	int T;
	cin >> T;

	for (int x = 0; x < T; x++) {
		int N;
		cin >> N;
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		for (int i = 4; i <= N; i++) {
			dp[i] = dp[i - 2] + dp[i - 3];
		}
		cout << dp[N] << "\n";
	}
	return 0;
}
//dp[1]부터 dp[10]정도까지 결과만 공책에 적어보면 쉽게 공식을 알 수 있는 문제