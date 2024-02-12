//boj2444번_별 찍기-7_구현

#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = N - i; j > 0; j--) {
			cout << " ";
		}
		for (int j = 2 * i - 1; j > 0; j--) {
			cout << "*";
		}
		cout << '\n';
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int j = 2 * (N - i) - 1; j > 0; j--) {
			cout << "*";
		}
		cout << '\n';
	}
}
//구현문제.
//별로 마름모 모양을 만드는 문제인데, 위 삼각형, 아래 역삼각형을 나눠서 출력하는 느낌으로 해결했다.