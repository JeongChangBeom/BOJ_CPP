//boj11501번_주식_그리디 알고리즘

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		vector<int> v;
		int max = -999;
		long long result = 0;

		for (int i = 0; i < N; i++) {
			int value;
			cin >> value;
			v.push_back(value);
		}

		for (int i = N - 1; i >= 0; i--) {
			max = std::max(max, v[i]);
			result += max - v[i];
		}

		cout << result << '\n';
	}
}