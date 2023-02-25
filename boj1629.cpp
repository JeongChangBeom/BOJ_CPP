//boj1629번_곱셈_분할정복을 이용한 거듭제곱

#include<iostream>

using namespace std;


long long pow(long long a, long long b, long long c) {
	if (b == 0) {
		return 1;
	}
	if (b == 1) {
		return a % c;
	}
	long long half = pow(a, b / 2, c);
	if (b % 2 == 0) {
		return (half * half) % c;
	}
	else {
		return(((half) * (half) %c * a )% c);
	}
}

int main() {
	ios::sync_with_stdio(false); //입출력 가속
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	cout << pow(a, b, c);
}

//겉보기에는 엄청 쉬워 보이는 문제지만 시간제한이 0.5초 걸려있어서 어려웠던 문제.
//a^b = a^(b/2) x a^(b/2) <- 이러한 분할정복을 이용한 거듭제곱을 사용해서 풀 수 있었다.
//0.5초를 맞추기위해 중간중간 모듈러 연산을 하는 것이 중요하다고 생각한다.