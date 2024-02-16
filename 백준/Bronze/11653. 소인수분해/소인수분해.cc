//boj11653번_소인수분해_수학

#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i * i <= N; i++) {
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
			while (N % i == 0) {
				cout << i << '\n';
				N /= i;
			}
		}
	}
	if (N > 1) {
		cout << N;
	}
}