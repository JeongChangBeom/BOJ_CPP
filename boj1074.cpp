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
//분할정복을 사용해서 해결할 수 있는 문제. 입력받은 그래프(2^N 크기의 그래프)를 4분면으로 나눠 탐색하면 된다.
//r,c가 현재 사분면안에 존재하면 4등분하고, 없으면 result에 현재 사분면의 크기를 더해주는 것이 핵심이다.