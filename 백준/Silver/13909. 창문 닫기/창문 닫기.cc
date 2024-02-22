//boj13909번_창문 닫기_수학

#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int result = 0;

	for (int i = 1; i * i <= N; i++) {
		result++;
	}
	cout << result;
}