//boj1735번_분수 합_수학

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
	int A1, B1;
	int A2, B2;
	cin >> A1 >> B1;
	cin >> A2 >> B2;

	int sum = A1 * ((B1 * B2 / gcd(B1, B2)) / B1) + A2 * ((B1 * B2 / gcd(B1, B2)) / B2);

	cout << sum / gcd(sum, (B1 * B2 / gcd(B1, B2))) << " " << ((B1 * B2 / gcd(B1, B2)) / gcd(sum, (B1 * B2 / gcd(B1, B2))));
}