//boj2903번_중앙 이동 알고리즘_수학

#include<iostream>
#include<cmath>

using namespace std;

int pow_int(int x, int y) {
	int result = 1;

	for (int i = 0; i < y; i++) {
		result = result * x;
	}

	return result;
}

int main() {
	int N;
	cin >> N;

	cout << pow_int(1 + pow_int(2, N), 2);
}