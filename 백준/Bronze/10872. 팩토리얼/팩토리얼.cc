//boj24723번_녹색거탑_수학

#include<iostream>

using namespace std;

int factorial(int x) {
	if (x == 0 || x == 1) {
		return 1;
	}

	return x * factorial(x - 1);
}

int main() {
	int N;
	cin >> N;
	cout << factorial(N);
}