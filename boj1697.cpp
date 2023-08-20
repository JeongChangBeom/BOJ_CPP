//boj1697번_숨바꼭질_그래프(너비우선탐색)

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int visited[200001];

int main() {
	int N, K;
	cin >> N >> K;

	queue<int> q;
	q.push(N);

	visited[N] = 1;

	while (q.empty() == false) {
		int V = q.front();
		q.pop();

		if (V == K) {
			cout << visited[V] - 1;
			break;
		}
		if (V >= 0 && V <= 100000) {
			if (visited[V - 1] == 0) {
				visited[V - 1] = visited[V] + 1;
				q.push(V - 1);
			}
			if (visited[V + 1] == 0) {
				visited[V + 1] = visited[V] + 1;
				q.push(V + 1);
			}
			if (visited[V * 2] == 0) {
				visited[V * 2] = visited[V] + 1;
				q.push(V * 2);
			}
		}
	}

	return 0;
}
//BFS로 간단하게 풀 수 있는 문제.
//동생을 못 찾으면 V-1,V+1,V*2를 해서 방문했었는지 확인을 하고 방문을 하지 않았을경우 큐에 넣어주면 된다.