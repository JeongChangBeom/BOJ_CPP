//boj9658번_돌 게임4_dp

#include<iostream>

using namespace std;

bool dp[1001];

int main() {
	int N;
	cin >> N;

	dp[1] = false;
	dp[2] = true;
	dp[3] = false;
	dp[4] = true;

	for (int i = 5; i <= N; i++) {
		if (dp[i - 1] == true && dp[i - 3] == true && dp[i - 4] == true) {
			dp[i] = false;
		}
		else {
			dp[i] = true;
		}
	}

	if (dp[N] == true) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}
}