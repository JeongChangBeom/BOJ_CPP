//boj1850번_최대공약수와 최소공배수_수학

#include<iostream>

using namespace std;

long long GCD(long long x, long long y) {
	if (y == 0) {
		return x;
	}
	else {
		return GCD(y, x % y);
	}
}

int main()
{
	long long x, y;
	cin >> x >> y;

	for (long long i = 0; i < GCD(x, y); i++) {
		cout << "1";
	}

	return 0;
}