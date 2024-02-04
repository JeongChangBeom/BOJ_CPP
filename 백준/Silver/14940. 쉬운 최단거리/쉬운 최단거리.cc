//boj14940번_쉬운 최단거리_BFS

#include<iostream>
#include<queue>

using namespace std;

int graph[1001][1001];
int result[1001][1001];
bool visited[1001][1001];
int xy[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n, m;

void BFS(int x, int y) {
	visited[x][y] = true;

	queue<pair<int, int>> q;

	q.push(make_pair(x, y));

	while (!q.empty()) {
		pair<int, int> cur = q.front();

		for (int i = 0; i < 4; i++) {
			int x2 = cur.first + xy[i][0];
			int y2 = cur.second + xy[i][1];

			if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && graph[x2][y2] && !visited[x2][y2]) {
				visited[x2][y2] = true;
				q.push(make_pair(x2, y2));
				result[x2][y2] = result[cur.first][cur.second] + 1;
			}
		}
		q.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[i][j] = -1;
		}
	}

	int a = 0;
	int b = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 2) {
				result[i][j] = 0;
				a = i;
				b = j;
			}
			else if (graph[i][j] == 0) {
				result[i][j] = 0;
			}
		}
	}

	BFS(a, b);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << result[i][j] << " ";
		}
		cout << '\n';
	}
}
//BFS(너비우선탐색문제)
//어려운 문제는 아닌 것 같은데 그래프 문제가 오랜만이라서 어려웠던 것 같다.
//먼저 문제에 도달할 수 없으면 -1을 출력하라는 조건이 있기 때문에 result배열을 -1로 초기화 한다.
//이후 지도배열(graph)를 입력받으면서 목표지점(2)과 벽을 찾는다. 목표지점은 위치를 a와 b를 통해 저장해둔다. (목표지점과 벽은 0으로 초기화)
//그리고 BFS를 통해 지도배열을 돌면서 xy배열에 저장된 값을 통해 4방향을 탐색하면 된다.