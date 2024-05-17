//boj1325번_효율적인 해킹_그래프

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;

vector<int >graph[10001];
bool visited[10001];

int cnt = 0;

void DFS(int V) {
	visited[V] = true;
	cnt++;

	for (int i = 0; i < graph[V].size(); i++) {
		if (!visited[graph[V][i]]) {
			DFS(graph[V][i]);
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int A, B;
		cin >> A >> B;
		graph[B].push_back(A);
	}

	int max = 0;
	vector<pair<int,int>> result;

	for (int i = 1; i <= n; i++) {
		DFS(i);

		max = std::max(max, cnt);

		result.push_back({i,cnt});

		cnt = 0;

		for (int i = 0; i < 10001; i++) {
			visited[i] = false;
		}
	}

	for (int i = 0; i < result.size(); i++) {
		if (max == result[i].second) {
			cout << result[i].first << " ";
		}
	}

	return 0;

}