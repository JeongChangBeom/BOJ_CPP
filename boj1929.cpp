//boj1929번_소수 구하기_수학

#include<iostream>
#include<cmath>

using namespace std;

bool isPrime_Eratos(int x) {
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
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = N; i <= M; i++) {
		if (isPrime_Eratos(i)) {
			cout << i << "\n";
		}
	}
}
//전에 풀었던 소수 찾기 문제와 아주 유사한 문제이다. 소수 찾기 문제는 에라토스테네스의 체로
//풀지 않아도 시간초과가 나지 않지만 이 문제는 에라토스테네스의 체로 풀어야 시간초과가 안나온다.
//에라토스테네스의체(O(nlog(logn)));