#include <iostream>

using namespace std;

int graph[51][51];
bool visited[51][51];

int xy[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{-1,1},{-1,-1},{1,1},{1,-1} };


void DFS(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int x2 = x + xy[i][0];
		int y2 = y + xy[i][1];
		if (x2 >= 0 && x2 <= 50 && y2 >= 0 && y2 <= 50 && graph[x2][y2] && !visited[x2][y2]) {
			DFS(x2, y2);
		}
	}
}

int main() {
	while (true) {
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0) {
			return 0;
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				visited[i][j] = 0;
				int num;
				cin >> num;
				graph[i][j] = num;
			}
		}
		int count = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (graph[i][j] && !visited[i][j]) {
					DFS(i, j);
					count++;
				}
			}
		}
		cout << count << "\n";
	}
}
//DFS로 해결한 문제.
//섬이 가로,세로,대각선으로 연결되어 있으면 DFS를 계속 진행해주고, DFS가 끝날때 count를 세주면된다.