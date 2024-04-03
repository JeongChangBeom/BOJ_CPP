//boj1789번_수들의 합_그리디 알고리즘

#include<iostream>

using namespace std;

int main() {
	long long S;
	cin >> S;

	int num = 1;

	while (S > 0) {
		S -= num;
		num++;
	}

	if (S < 0) {
		num--;
	}

	cout << num - 1;
}