//boj6236번_용돈 관리_이분 탐색

#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v;

	int start = 0;
	int end = 0;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);

		start = max(start, num);
		end += num;
	}

	int result = 0;

	while (start <= end) {
		int mid = (start + end) / 2;
		int count = 1;
		int money = mid;
		bool check = false;

		for (int i = 0; i < N; i++) {
			if (v[i] > mid) {
				start = mid + 1;
			}

			if (money >= v[i]) {
				money -= v[i];
			}
			else {
				money = mid - v[i];
				count++;
			}
		}

		if (count > M) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
			result = mid;
		}
	}

	cout << result;

	return 0;
}