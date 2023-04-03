//boj11727번_2xN 타일링 2_dp

#include <iostream>
#include <vector>

using namespace std;


int main() {
	int x;
	cin >> x;

	vector <int> dp(1001);

	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	dp[4] = 11;

	for (int i = 5; i <= x; i++) {
		dp[i] = ((dp[i - 2] * 2) + dp[i - 1]) % 10007;
	}

	cout << dp[x] % 10007 << "\n";

	return 0;
}
//전에 풀었던 2xN 타일링 문제의 확장느낌인 문제. 2xN 타일링 문제와 다르게 2x2 타일이 생겨
//점화식의 dp[i-2]부분에 2를 곱해주는 것이 핵심. 2x2 = 1x2(or 2x1) * 2