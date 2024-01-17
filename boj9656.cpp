//boj9656번_돌 게임2_dp

#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	int dp[1001];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
	}

	if ((dp[N] % 2) == 1) {
		cout << "CY";
	}
	else {
		cout << "SK";
	}
}
//옛날에 풀었던 돌 게임 문제와 매우 유사한 문제.
//돌은 1개 or 3개 가져올 수 있으므로 i-1번째 에서 1개 더 가져오거나 i-3에서 3개 더 가져오는 경우에서 더 작은 수를 골라 홀짝을 판단해주면 된다.
//따라서 dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1)의 값이 홀수면 창용이의 승리, 짝수면 상근이의 승리이다.