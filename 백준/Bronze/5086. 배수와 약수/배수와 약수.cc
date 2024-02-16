//boj5086번_배수와 약수_수학

#include<iostream>

using namespace std;

int main() {
	while (true) {
		int x, y;
		cin >> x >> y;

		if (x == 0 && y == 0) {
			return 0;
		}

		if (y % x == 0) {
			cout << "factor" << '\n';
		}

		else if (x % y == 0) {
			cout << "multiple" << '\n';
		}
		else {
			cout << "neither" << '\n';
		}
	}
}