//boj13241번_최소공배수_수학

#include<iostream>

using namespace std;

int gcd(long long x, long long y) {
	long long num;
	while (y != 0) {
		num = x % y;
		x = y;
		y = num;
	}
	return x;
}

int main() {
	long long A, B;
	cin >> A >> B;

	cout << A * B / gcd(A, B);
}