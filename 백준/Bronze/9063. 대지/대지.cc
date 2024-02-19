//boj9063번_대지_구현

#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int x_min = 99999;
	int x_max = -99999;

	int y_min = 99999;
	int y_max = -99999;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		if (x < x_min) {
			x_min = x;
		}
		if (x > x_max)
		{
			x_max = x;
		}
		if (y < y_min) {
			y_min = y;
		}
		if (y > y_max)
		{
			y_max = y;
		}
	}
	cout << (x_max - x_min) * (y_max - y_min);
}