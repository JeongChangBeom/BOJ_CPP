//boj2210번_숫자판 점프_그래프

#include<iostream>
#include<set>

using namespace std;

char graph[5][5];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

set<string> result;

void DFS(int x, int y, string num, int cnt) {
	if (cnt == 6) {
		result.insert(num);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < 5 && next_y >= 0 && next_y < 5) {
			DFS(next_x, next_y, num + graph[next_x][next_y], cnt + 1);
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			DFS(i, j, "" + graph[i][j], 0);
		}
	}

	cout << result.size();
}