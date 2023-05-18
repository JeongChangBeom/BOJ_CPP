//boj10026번_적록색약_그래프

#include<iostream>

using namespace std;

char graph[101][101];
bool visited[101][101];

int N;
int cnt = 0;
int cnt2 = 0;

int xy[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void DFS(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int x2 = x + xy[i][0];
		int y2 = y + xy[i][1];
		if (x2 >= 0 && x2 < 101 && y2 >= 0 && y2 < N && graph[x2][y2] == graph[x][y] && !visited[x2][y2]) {
			visited[x2][y2] = true;
			DFS(x2, y2);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> graph[i];
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				cnt++;
				DFS(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 'G') {
				graph[i][j] = 'R';
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				cnt2++;
				DFS(i, j);
			}
		}
	}

	cout << cnt << " " << cnt2;
}
//DFS로 구현할 수 있는 문제, 적록색맹일 경우 DFS하기전에 그래프에서 'G'를 'R'로만 바꿔주면 된다.