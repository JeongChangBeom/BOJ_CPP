//boj2193번_이친수_dp

#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	long long dp[91];

	dp[1] = 1;
	dp[2] = 1;
	
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[N];
}
//이문제는 dp[i] = dp[i - 2] + dp[i - 1]라는 점화식을 얻어 피보나치 수열과 같은 dp식으로 풀 수 있는데
//입력으로 받는 값의 최대치가 90이므로 int타입을 쓰면 int의 범위를 넘어 틀리게 된다. (long long타입을 사용하자)