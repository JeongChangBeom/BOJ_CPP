//boj4948번_베르트랑 공준_수학

#include<iostream>

using namespace std;

bool arr[246913];

bool isPrime_Eratos(int x) {
	if (x == 1) {
		return false;
	}
	else {
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}
}

int main() {
	while (true) {
		int n;
		cin >> n;

		if (n == 0) {
			break;
		}

		int result = 0;

		for (int i = n + 1; i <= 2 * n; i++) {
			if (isPrime_Eratos(i)) {
				result++;
			}
		}
		cout << result << '\n';
	}
}
//에라토스 테네스의 체를 이용해서 소수판별 함수를 만들 때
//for문의 범위를 i <= sqrt(x)로 하면 sqrt함수의 수행시간이 오래걸려 시간초과가 난다.
//for문의 범위를 i*i <= x로 만드는 것을 명심하자.