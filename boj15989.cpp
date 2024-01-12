//boj15989번_1,2,3 더하기 4_dp

#include<iostream>

using namespace std;

int dp[10001];

int main() {
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 10001; i++) {
			dp[i] = 0;
		}

		int N;
		cin >> N;

		dp[0] = 1;

		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= N; j++) {
				dp[j] += dp[j - i];
			}
		}

		cout << dp[N] << '\n';
	}
}

//dp 문제. 1이하, 2이하, 3이하의 숫자들로 N을 만들 수 있는 경우의 수를 구하는 문제이다.
//바텀업 방식으로 dp에 값을 누적해가면서 풀면 쉽게 해결할 수 있다.
//dp배열에 누적해가며 해결했다.