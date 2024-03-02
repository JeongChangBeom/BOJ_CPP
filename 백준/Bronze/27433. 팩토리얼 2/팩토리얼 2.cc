//boj27433번_팩토리얼 2_재귀

#include<iostream>

using namespace std;

long long factorial(int x) {
	if(x == 0 || x == 1) {
		return 1;
	}
	return x * factorial(x - 1);
}

int main() {
	int N;
	cin >> N;
	cout << factorial(N);
 }