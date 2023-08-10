//boj14501번_퇴사_dp

#include<iostream>
#include<vector>

using namespace std;

int T[16];
int P[16];
int dp[16];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = N; i >= 1; i--) {
		if (i + T[i] - 1 > N) {
			dp[i] = dp[i + 1];
			continue;
		}
		dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);
	}
	cout << dp[1];
}
//dp로 해결한 문제. 뒷날부터 생각해서 N+1일에는 회사에 없어 상담을 할 수 없다는 조건을 if문을 통해 해결했고
//나머지는 오늘 일을 해서 벌 수 있는 금액과 오늘 일을하지 않고 전까지 일해서 번 돈의 최대값을 비교하며 해결했다.