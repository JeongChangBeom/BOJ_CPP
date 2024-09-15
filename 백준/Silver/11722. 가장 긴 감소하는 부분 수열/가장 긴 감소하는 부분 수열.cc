//boj11722번_가장 긴 감소하는 부분 수열

#include <iostream>
#include <algorithm>

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
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		result = max(result, dp[i]);
	}

	cout << result;

	return 0;
}