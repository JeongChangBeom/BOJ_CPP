//boj11050번_이항 계수1_수학

#include<iostream>

using namespace std;

int factorial(int x) {
	if (x <= 1) {
		return 1;
	}
	return x * factorial(x - 1);
}

int main() {
	int N, K;
	cin >> N >> K;

	cout << factorial(N) / (factorial(N - K) * factorial(K));
}
//이항계수에 대한 공식을 알면 쉽게 풀 수 있는 문제.
//nCk = n!/(n-k)!k!