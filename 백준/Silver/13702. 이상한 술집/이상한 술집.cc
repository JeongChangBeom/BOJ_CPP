//boj13702번_이상한 술집_이분 탐색

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int mak;
		cin >> mak;
		v.push_back(mak);
	}

	sort(v.begin(), v.end());

	long long start = 1;
	long long end = v[v.size() - 1];

	long long result = 0;

	while (start <= end) {
		int count = 0;
		long long mid = (start + end) / 2;

		for (int i = 0; i < v.size(); i++) {
			count += v[i] / mid;
		}

		if (count >= K) {
			start = mid + 1;
			result = mid;
		}

		if (count < K) {
			end = mid - 1;
		}
		else if (count > K) {
			start = mid + 1;
		}
	}

	cout << result;

	return 0;
}