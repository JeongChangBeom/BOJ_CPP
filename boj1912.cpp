//boj1912번_연속합_dp

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	vector<int> dp;

	dp.push_back(v.front());

	for (int i = 1; i < N; i++) {
		dp.push_back(max(v[i], dp[i - 1] + v[i]));
	}

	cout << *max_element(dp.begin(), dp.end());
}
//연속된 임의의 개수의 숫자의 합이 가장큰 경우를 구하는 문제.
//dp를 사용해서 현재값 이랑 현재값+지금까지 누적값을 비교하여 더 큰 경우를 구하면 된다.