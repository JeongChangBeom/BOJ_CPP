//boj1965번_상자넣기_dp

#include<iostream>
#include<algorithm>

using namespace std;

int dp[1001];
int arr[1001];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	cout << *max_element(dp, dp + N + 1);

	return 0;
}