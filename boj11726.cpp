//boj11726번_2xn 타일링_dp

#include <iostream>
#include <vector>

using namespace std;


int main() {
	int x;
	cin >> x;

	vector <int> dp(1001);

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= x; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007; //여기서 모듈러 연산을 안하고 출력할 때 하면 틀림
	}

	cout << dp[x] << endl;

	return 0;
}
//점화식만 알아내면 쉽게 풀 수 있는 문제