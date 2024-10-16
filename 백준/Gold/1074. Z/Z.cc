//boj1074번_Z_분할정복

#include<iostream>
#include<cmath>

using namespace std;

int N, r, c;
int result = 0;

void Z(int x, int y, int size) {
	if (x == c && y == r) {
		cout << result;
		return;
	}
	if (c < x + size && r < y + size && c >= x && r >= y) {
		Z(x, y, size / 2);
		Z(x + size / 2, y, size / 2);
		Z(x, y + size / 2, size / 2);
		Z(x + size / 2, y + size / 2, size / 2);
	}
	else {
		result += size * size;
	}
}

int main() {
	cin >> N;
	cin >> r >> c;

	Z(0, 0, pow(2,N));
}