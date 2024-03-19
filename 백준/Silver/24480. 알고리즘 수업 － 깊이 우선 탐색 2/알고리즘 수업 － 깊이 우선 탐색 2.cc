//boj24479번_알고리즘 수업-깊이 우선 탐색 1_그래프

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> graph[100001];
bool visited[100001];
int result[100001];
int cnt = 1;

bool compare(int x, int y) {
	return x > y;
}

void DFS(int V) {
	if (visited[V]) {
		return;
	}

	visited[V] = true;
	result[V] = cnt;
	cnt++;

	sort(graph[V].begin(), graph[V].end(),compare);

	for (int i = 0; i < graph[V].size(); i++) {
		DFS(graph[V][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, R;
	cin >> N >> M >> R;

	for (int i = 0; i < M; i++) {
		int V1, V2;
		cin >> V1 >> V2;

		graph[V1].push_back(V2);
		graph[V2].push_back(V1);
	}

	DFS(R);

	for (int i = 1; i <= N; i++) {
		cout << result[i] << '\n';
	}
}