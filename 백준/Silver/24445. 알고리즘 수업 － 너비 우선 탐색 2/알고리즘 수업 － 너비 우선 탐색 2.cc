//boj24445번_알고리즘 수업 - 너비 우선 탐색 1_그래프

#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> graph[100001];
bool visited[100001];
int result[100001];
int cnt = 0;

bool compare(int x, int y) {
	return x > y;
}

void BFS(int V) {
	visited[V] = true;
	queue<int> q;
	q.push(V);
	cnt++;
	result[V] = cnt;

	while (!q.empty()) {
		V = q.front();
		q.pop();

		for (int i = 0; i < graph[V].size(); i++) {
			int num = graph[V][i];

			if (!visited[num]) {
				visited[num] = true;
				cnt++;
				result[num] = cnt;

				q.push(num);
			}
		}
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

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(), compare);
	}

	BFS(R);

	for (int i = 1; i <= N; i++) {
		cout << result[i] << '\n';
	}
}
