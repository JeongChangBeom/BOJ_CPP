//boj1934번_최소공배수_수학

#include<iostream>

using namespace std;

int gcd(int x, int y) {
	int num;
	while (y != 0) {
		num = x % y;
		x = y;
		y = num;
	}
	return x;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int A, B;
		cin >> A >> B;

		cout << A * B / gcd(A, B) << '\n';
	}
}