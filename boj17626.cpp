//boj17626번_Four Squares_dp

#include<iostream>

using namespace std;

int dp[50001];

int main() {
	int n;
	cin >> n;

	dp[1] = 1;


	for (int i = 1; i <= n; i++) {
		dp[i] = dp[1] + dp[i - 1];

		for (int j = 2; j * j <= i; j++)
		{
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}

	cout << dp[n];
}
//dp문제. dp는 난이도에 상관없이 항상 어려운것 같다.
//1,4,9,16같은 제곱수는 항상 1이므로 만약 dp[30]을 구한다면
//dp[1] + dp[29], dp[4] + dp[26], dp[9] + dp[21], dp[16] + dp[14], dp[25] + dp[5] 중 가장 작은 값이 답이된다.
//따라고 점화식은 dp[i] = 1 + dp[i-j*j]가 된다.