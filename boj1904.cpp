//boj1904번_01타일_dp

#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];
int tile[1000001];

int main() {
	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;


	for (int i = 5; i <= N; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
	}
	cout << dp[N];
}
//dp 문제. 규칙성을 찾다보면 피보나치 수열과 동일함을 알 수 있으며
//계산을 할 때 모듈러계산을 하지않으면 범위를 벗어나므로 주의해야된다.