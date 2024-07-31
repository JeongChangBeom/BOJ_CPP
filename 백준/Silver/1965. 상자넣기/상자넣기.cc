//boj1965번_상자넣기_dp

#include<iostream>

using namespace std;

int dp[1001];
int arr[1001];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	int result = 0;

	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		if (result < dp[i]) {
			result = dp[i];
		}
	}

	cout << result;

	return 0;
}