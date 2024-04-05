//boj16401번_과자 나눠주기_이분 탐색

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int M, N;
	cin >> M >> N;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int L;
		cin >> L;
		v.push_back(L);
	}

	sort(v.begin(), v.end());

	int start = 1;
	int end = v[v.size() - 1];

	int result = 0;

	while (start <= end) {
		int mid = (start + end) / 2;
		int count = 0;
		for (int i = 0; i < N; i++) {
			count += v[i] / mid;
		}

		if (count >= M) {
			start = mid + 1;
			result = mid;
		}
		else {
			end = mid - 1;
		}
	}

	cout << result;
}