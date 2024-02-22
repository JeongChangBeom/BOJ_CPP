//boj17103번_골드바흐 파티션_수학

#include<iostream>

using namespace std;

bool isPrime[1000001];

int main() {
	int T;
	cin >> T;

	for (int i = 2; i <= 1000000; i++) {
		isPrime[i] = true;
	}

	for (int i = 2; i <= 1000000; i++) {
		for (int j = i * 2; j <= 1000000; j += i) {
			isPrime[j] = false;
		}
	}

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		int result = 0;

		for (int i = 2; i <= N / 2; i++) {
			if (isPrime[N - i] && isPrime[i]) {
				result++;
			}
		}
		cout << result << '\n';
	}
}