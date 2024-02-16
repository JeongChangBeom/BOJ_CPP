//boj2581번_소수_수학

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int M, N;
	cin >> M >> N;

	vector<int> v;

	for (int i = M; i <= N; i++) {
		bool check = true;

		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				check = false;
			}
		}
		if (i == 1) {
			check = false;
		}

		if (check) {
			v.push_back(i);
		}
	}

	sort(v.begin(), v.end());

	int sum = 0;

	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}

	if (v.empty()) {
		cout << "-1";
	}
	else {
		cout << sum << '\n' << v[0];
	}
}