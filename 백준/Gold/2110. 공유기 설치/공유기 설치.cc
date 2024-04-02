//boj2110번_공유기 설치_이분탐색

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, C;
	cin >> N >> C;

	vector<int> v;

	for (int i = 0; i < N; i++) {
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
		int temp = v[0];
		int count = 1;

		for (int i = 1; i < N; i++) {
			if (temp + mid <= v[i]) {
				temp = v[i];
				count++;
			}
		}

		if (count < C) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
			result = mid;
		}
	}
	cout << result;
}