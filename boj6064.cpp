//boj6064번_카잉 달력_수학

#include<iostream>

using namespace std;

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
}

int lcm(int x, int y) {
	return (x * y) / gcd(x, y);
}

int main() {
	int T;
	cin >> T;
	
	for (int k = 0; k < T; k++) {
		int M, N, x, y;
		int temp = 0;

		cin >> M >> N >> x >> y;

		for (int i = x; i <= lcm(M, N); i += M) {
			temp = i % N;

			if (temp == 0) {
				temp = N;
			}

			if (temp == y) {
				cout << i << '\n';
				break;
			}
		}
		if (temp != y) {
			cout << "-1" << '\n';
		}
	}
}
//m,n을 토대로 <x,y>를 나태내는 방법은 x는 m , y는 n으로 나눈 나머지로 나태낼 수 있는데
//이 값을 구하기 위해 <1,1>부터 시작해서 증가시켜주면서 검사하면된다.
//문제에서 주어진 검사의 끝은 멸망해를 통해 알 수 있는데 멸망해는 M과 N의 최소 공배수이다.