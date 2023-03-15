//boj1978번_소수 찾기_수학

#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int arr[101];

/*bool isPrime_Eratos(int x) { <-에라토스테네스의 체
	if (x == 1) {
		return false;
	}
	else {
		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}
}*/

bool isPrime(int x) {
	int cnt = 0;

	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			cnt++;
		}
	}
	if (cnt == 2) {
		return true;
	}
	return false;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int result = 0;

	for (int i = 0; i < N; i++) {
		if (isPrime(arr[i])) {
			result++;
		}
	}
	cout << result;
}
//입력받은 배열을 소수인지 판단하는 함수를 만들어 풀었다.
//입력받은 수를 나누어 떨어지게 하는 수가 2개면(1과 자신) 소수라고 판단하였다.
//위 주석같이 에라토스테네스의 체를 사용해서 풀 수도 있을 것 같다.