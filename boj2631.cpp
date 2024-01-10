//boj2631번_줄세우기_dp, LIS

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(N + 1);
	vector<int> dp(N + 1, 1);

	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		v[i] = num;
	}

	int result = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (v[i] > v[j] && dp[i] < dp[j] + 1) {
				dp[i]++;
			}
		}
		result = max(result, dp[i]);
	}

	cout << N - result;
}
//어떻게 해결해야될지 고민을 많이 했던 문제이다.
//공부를 통해 LIS(최장 부분 증가 수열)을 이용해서 풀면된다는 것을 알게되었다.
//무작위로 서있는 어린이들중 최장 부분 증가 수열을 찾아 그 부분수열은 놔두고 나머지 어린이들을 오름차순으로 정렬하는 식으로 해결하면된다.
//그렇기 때문에 dp를 이용해서 LIS를 구하고 전체 어린이의 수에서 LIS의 길이를 빼주면 해결할 수 있다.