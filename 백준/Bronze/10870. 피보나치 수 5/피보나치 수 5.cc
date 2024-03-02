//boj10870번_피보나치 수 5_재귀

#include<iostream>

using namespace std;


long long fibonacci(int x) {
	if (x == 0 || x == 1) {
		return x;
	}
	return fibonacci(x - 1) + fibonacci(x - 2);
}

int main() {
	int N;
	cin >> N;
	cout << fibonacci(N);
}
