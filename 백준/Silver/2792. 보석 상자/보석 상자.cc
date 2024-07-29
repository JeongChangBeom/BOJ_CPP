//boj2792번_보석 상자_이분 탐색

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int start = 1;
	int end = v[v.size() - 1];

	int result = 0;
	
	while (start <= end) {
		int mid = (start + end) / 2;

		int count = 0;

		for (int i = 0; i < M; i++) {
			count += v[i] / mid;
			if (v[i] % mid) {
				count++;
			}
		}

		if (count <= N) {
			end = mid - 1;
			result = mid;
		}
		else {
			start = mid + 1;
		}
	}

	cout << result;

	return 0;
}