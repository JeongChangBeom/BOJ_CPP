//boj2606번_바이러스_그래프

#include<iostream>

using namespace std;

int computer[101][101];
bool visited[101];
int N, M;
int result = 0;

void DFS(int V) {
	visited[V] = true;

	for (int i = 1; i <= N; i++) {
		if (computer[V][i] == 1 && visited[i] == false) {
			result++;
			DFS(i);
		}
	}
}

int main() {
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		computer[x][y] = 1;
		computer[y][x] = 1;
	}

	DFS(1);

	cout << result;
}
//DFS를 사용해 해결한 문제. 연결되어있는 그래프를 1로 초기화하고 DFS를 통해 탐색해주면서
//탐색하는 수 만큼 result를 올려주면 답이 나온다.