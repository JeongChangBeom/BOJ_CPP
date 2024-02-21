//boj4134번_다음 소수_브루트포스

#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(long long x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		long long n;
		cin >> n;

		if (n == 0 || n == 1) {
			cout << 2 << '\n';
		}
		else {
			while (true) {
				if (isPrime(n)) {
					cout << n << '\n';
					break;
				}
				else {
					n++;
				}
			}
		}
	}
}
//브루트포스 문제.
//에라토스테네스의 체를 이용해서 소수인지 판별하고
//소수가 아닐시 1씩 늘려가며 입력받은 수보다 크면서 소수인 수 중 가장 작은 수를 찾는 식으로 해결했다.