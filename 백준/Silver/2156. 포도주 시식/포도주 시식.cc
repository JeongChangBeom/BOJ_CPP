//boj2156번_포도주 시식_dp

#include<iostream>
#include<vector>


using namespace std;

int dp[10001];
vector<int> v;

int main() {
	int n;
	cin >> n;

	v.push_back(0);

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}

	dp[0] = 0;
	dp[1] = v[1];
	dp[2] = v[1] + v[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]));
	}

	cout << dp[n];
}