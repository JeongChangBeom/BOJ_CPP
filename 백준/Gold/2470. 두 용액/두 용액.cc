//boj2470번_두 용액_두 포인터

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

	sort(v.begin(), v.end());

	int start = 0;
	int end = v.size() - 1;
	int min = 2147483647;

	int result_1 = 0;
	int result_2 = 0;

	while (start < end) {
		if (min > abs(v[start] + v[end])) {
			result_1 = v[start];
			result_2 = v[end];

			min = abs(v[start] + v[end]);
		}

		if (v[start] + v[end] < 0) {
			start++;
		}
		else {
			end--;
		}
	}
	cout << result_1 << " " << result_2;

	return 0;
}