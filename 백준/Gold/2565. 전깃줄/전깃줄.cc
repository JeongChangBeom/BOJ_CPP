//boj2565번_전깃줄_dp

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[101];

struct cross {
	int a;
	int b;
};

bool compare(cross x, cross y) {
	if (x.a < y.a) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int N;
	cin >> N;

	vector<cross> v;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		cross c;

		c.a = x;
		c.b = y;

		v.push_back(c);
	}

	sort(v.begin(), v.end(), compare);

	int b_line[101];

	int result = 0;

	for (int i = 1; i <= N; i++) {
		b_line[i] = v[i-1].b;
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (b_line[i] > b_line[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		result = max(result, dp[i]);
	}

	cout << N - result;

	return 0;
}