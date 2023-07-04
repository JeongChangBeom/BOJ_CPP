//boj2667번_단지번호붙이기_그래프

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int graph[26][26];
bool visited[26][26];
int num;
vector <int> group;

int xy[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };


void DFS(int x, int y) {
	num++;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int x2 = x + xy[i][0];
		int y2 = y + xy[i][1];
		if (x2 >= 0 && x2 <= 25 && y2 >= 0 && y2 <= 25 && graph[x2][y2] && !visited[x2][y2]) {
			DFS(x2, y2);
		}
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &graph[i][j]);
		}
	}

	int count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 1 && !visited[i][j]) {
				DFS(i, j);
				group.push_back(num);
				num = 0;
				count++;
			}
		}
	}

	sort(group.begin(), group.end());

	cout << count << "\n";

	for (int i = 0; i < group.size(); i++) {
		cout << group[i] << "\n";
	}

	return 0;
}
//깊이 우선 탐색으로 해결할 수 있는 문제. 깊이 우선 탐색을 진행하면서 연결 그래프의 요소 개수를 세면 풀 수 있다.