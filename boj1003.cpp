//boj1003번_피보나치 함수_dp

#include<iostream>

using namespace std;

int dp[41];

int main() {
	int T; //테스트 케이스
	cin >> T;
	for (int i = 0; i < T; i++) {
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 1;

		for (int j = 3; j <= 40; j++) { //피보나치수를 dp를 이용해 구하기(시간 초과 방지)
			dp[j] = dp[j - 1] + dp[j - 2];
		}

		int N;
		cin >> N;

		if (N == 0) {
			cout << "1 0" << "\n";
		}
		else if (N == 1) {
			cout << "0 1" << "\n";
		}
		else {
			cout << dp[N - 1] << " " << dp[N] << "\n";
		}
	}
}
//0의 개수가 dp[N-1]개, 1의 개수가 dp[N]개인 규칙만 찾으면 쉽게 풀 수 있는 문제