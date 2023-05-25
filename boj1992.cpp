//boj1992번_쿼드트리_분할정복,재귀

#include<iostream>

using namespace std;

int graph[65][65];

void QuadTree(int x, int y, int size) {
	int index = graph[x][y];

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (graph[i][j] != index) {
				cout << '(';
				QuadTree(x, y, size / 2);
				QuadTree(x, y + size / 2, size / 2);
				QuadTree(x + size / 2, y, size / 2);
				QuadTree(x + size / 2, y + size / 2, size / 2);
				cout << ')';
				return;
			}
		}
	}
	cout << index;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &graph[i][j]);
		}
	}
	QuadTree(0, 0, N);
}
//분할 정복을 이용하여 시간복잡도 O(nlogn)으로 풀 수 있는 문제. 주어진 그래프가 전부 0 또는 1일 때 출력을 하고
//아닌 경우에 왼쪽위, 오른쪽위, 왼쪽아래, 오른쪽아래로 4등분하여 다시 그래프가 전부 0또는 1일 때 출력하는 재귀를 사용했다.