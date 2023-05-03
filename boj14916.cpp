//boj14916번_거스름돈_그리디 알고리즘

#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int count = 0;
	int result = 0;

	while (n > 0) {
		if (n % 5 == 0) {
			result = (n / 5) + count;
			cout << result;
			return 0;
		}
		else {
			n -= 2;
			count++;
		}
	}
	if (n == 0) {
		cout << count;
	}
	else {
		cout << "-1";
	}
}
//거스름돈을 최대한 5원으로 줄 수 있는 만큼 주고 나머지는 2원으로 주는 그리디 알고리즘으로 해결했다.