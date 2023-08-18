//boj9095번_1, 2, 3 더하기_dp

#include <iostream>
#include <vector>

using namespace std;


int main() {
	int x;
	cin >> x;

	for (int T = 0; T < x; T++) {
		int n;
		cin >> n;
		vector<int> dp(12);

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		cout << dp[n] << endl;
	}
	return 0;
}
//dp문제. 1, 2, 3의 합으로 정수를 표현하는 방법의 개수를 구하는 문제.
//1은 1가지, 2는 2가지, 3은 4가지, 4는 문제에서 알려준 대로 7가지이며
//이 수들을 통해 식을 유추할 수 있었다.