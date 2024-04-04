//boj6603번_로또_재귀

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	while (true) {
		int k;
		cin >> k;

		if (k == 0) {
			return 0;
		}

		vector<int> v;

		for (int i = 0; i < k; i++) {
			int S;
			cin >> S;
			v.push_back(S);
		}

		vector<bool> check;

		for (int i = 0; i < 6; i++) {
			check.push_back(true);
		}

		for (int i = 0; i < k - 6; i++) {
			check.push_back(false);
		}

		do {
			for (int i = 0; i < check.size(); i++) {
				if (check[i]) {
					cout << v[i] << " ";
				}
			}
			cout << '\n';
		} while (prev_permutation(check.begin(), check.end()));

		cout << '\n';
	}
}