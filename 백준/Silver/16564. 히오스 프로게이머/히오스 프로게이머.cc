//boj16564번_히오스 프로게이머_이분 탐색

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int X;
		cin >> X;

		v.push_back(X);
	}

	sort(v.begin(), v.end());

	int start = 1;
	int end = 1000000001;

	int result = 0;

	while (start <= end) {
		int mid = (start + end) / 2;
		long long sum = 0;

		for (int i = 0; i < v.size(); i++) {
			if (v[i] < mid) {
				sum += mid - v[i];
			}
		}

		if (sum <= K) {
			start = mid + 1;
			result = mid;
		}
		else {
			end = mid - 1;
		}
	}

	cout << result;

	return 0;
}