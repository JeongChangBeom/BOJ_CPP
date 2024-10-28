//boj9009번_피보나치_그리디 알고리즘

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int fib[46];

int main() {
	fib[0] = 0;
	fib[1] = 1;

	for (int i = 2; i < 46; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;

		int sum = 0;

		vector<int> result;

		for (int j = 45; j >= 0; j--) {
			if (n == sum) {
				break;
			}

			if (sum + fib[j] <= n) {
				sum += fib[j];
				result.push_back(fib[j]);
			}
		}

		sort(result.begin(), result.end());

		for (int k = 0; k <result.size(); k++) {
			cout << result[k] << " ";
		}
		cout << '\n';
	}

	return 0;
}