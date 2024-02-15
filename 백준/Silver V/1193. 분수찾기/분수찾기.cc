//boj1193번_분수찾기_구현

#include<iostream>

using namespace std;

int main() {
	int X;
	cin >> X;

	int count = 1;

	while (X > count) {
		X -= count;
		count++;
	}

	if (count % 2 == 0) {
		cout << X << '/' << count + 1 - X << '\n';
	}
	else {
		cout << count + 1 - X << '/' << X << '\n';
	}

}