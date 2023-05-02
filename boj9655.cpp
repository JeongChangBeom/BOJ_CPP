//boj9655번_돌 게임_dp

#include<iostream>
#include<vector>

using namespace std;

/* dp를 사용하지 않고 쉽게 풀 수 있지만 dp연습을 위해 dp를 활용
int main() {
	int N;
	cin >> N;

	if ((N % 2) == 0) {
		cout << "CY";
	}
	else {
		cout << "SK";
	}
}
*/

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

	if ((dp[N] % 2) == 0) {
		cout << "CY";
	}
	else {
		cout << "SK";
	}
}
//돌은 1개 or 3개 가져올 수 있으므로 i-1번째 에서 1개 더 가져오거나 i-3에서 3개 더 가져오는 경우에서
//더 작은 경우를 골라 2로 나눈후 나머지가 있는지 없는지 판단을 해주면 해결할 수 있다.
//*나머지가 있으면 게임을 끝내지 못함 '창영승', 나머지가 없으면 게임을 끝낸 것이므로 '상근승'