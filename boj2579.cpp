//boj2579번_계단 오르기_dp

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	vector <int> stairs(301);
	int x;
	cin >> x;
	for (int i = 1; i <= x; i++) {
		cin >> stairs[i];
	}

	vector <int> dp(301);

	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];
	dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);

	for (int i = 4; i <= x; i++) {
		dp[i] = max(stairs[i] + dp[i - 2], stairs[i] + stairs[i - 1] + dp[i - 3]);
	}

	cout << dp[x] << endl;

	return 0;
}
//dp문제. 계단이 2개 이하일 때랑 계단이 3개 이상일 때를 나눠서 생각하면 해결하기 쉬운문제.
//계단이 2개 이하일 경우 그냥 더하면 되고, 3개 이상을 경우는 연속으로 2개의 계단을 밟았을 때와
//1개를 건너 뛴 경우의 최대값을 구하면 된다.