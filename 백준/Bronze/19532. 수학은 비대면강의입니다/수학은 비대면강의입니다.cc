//boj19532번_수학은 비대면강의입니다_브루트포스

#include<iostream>

using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	for (int x = -999; x <= 999; x++) {
		for (int y = -999; y <= 999; y++) {
			if (a * x + b * y == c && d * x + e * y == f) {
				cout << x << " " << y;
				return 0;
			}
		}
	}
}
//브루트포스 알고리즘 문제.
//x와 y의 범위가 -999~999로 작으므로 -999부터999까지 2중for문을 통해
//넣어보면서 정답일때 출력해주면 된다.