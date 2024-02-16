//boj9506번_약수들의 합_구현

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;

		if (n == -1) {
			return 0;
		}

		vector<int> v;

		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				v.push_back(i);
			}
		}

		sort(v.begin(), v.end());

		int sum = 0;

		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
		}

		if (n == sum) {
			cout << n << " = ";
			for (int i = 0; i < v.size(); i++) {
				if (i == v.size() - 1) {
					cout << v[i] << '\n';
				}
				else {
					cout << v[i] << " + ";
				}
			}
		}
		else {
			cout << n << " is NOT perfect." << '\n';
		}
	}
}