//boj2630번_색종이 만들기_분할 정복

#include<iostream>
#include<algorithm>

using namespace std;

int graph[129][129];
int white, blue = 0;

void ColorPaper(int x, int y, int size) {
	int index = graph[x][y];

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (graph[i][j] != index) {
				ColorPaper(x, y, size / 2);
				ColorPaper(x, y + size / 2, size / 2);
				ColorPaper(x + size / 2, y, size / 2);
				ColorPaper(x + size / 2, y + size / 2, size / 2);
				return;
			}
		}
	}
	if (index == 0) {
		white++;
	}
	else {
		blue++;
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	ColorPaper(0, 0, N);

	cout << white << '\n' << blue;
}

//분할정복을 통한 재귀로 해결한 문제. 이전에 풀었던 쿼드트리 문제랑 거의 동일한 문제이다.