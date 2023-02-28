//boj1463번_1로 만들기_dp

#include<iostream>
#include<algorithm>

using namespace std;

int dp[5001];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= 5000; i++) {
		dp[i] = 999999; //3 이나 5로 딱 나누어 떨어지지 않을때 min의 값으로 나누어지는 값이 나오게 하기 위하여 큰값으로 초기화
	}

	dp[3] = 1;
	dp[5] = 1;

	for (int i = 6; i <= N; i++) {
		dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
	}

	if (dp[N] >= 5001) {
		cout << "-1";
	}
	else {
		cout << dp[N];
	}
}
//바텀업 방식으로 쉽게 풀 수 있었던 문제
//입력 받은 수를 5로 먼저 나누고 그 다음 3으로 나누는 식의 그리디 알고리즘으로도 풀 수 있을 것 같다.