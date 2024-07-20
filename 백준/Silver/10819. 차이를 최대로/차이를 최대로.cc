//boj10819번_차이를 최대로_브루트포스 알고리즘

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

	int result = 0;

	do {
		int sum = 0;

		for (int i = 0; i < N - 1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}

		result = max(result, sum);

	} while (next_permutation(v.begin(), v.end()));

	cout << result;

	return 0;
}