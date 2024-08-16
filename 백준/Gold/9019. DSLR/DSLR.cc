//boj9019번_DSLR_그래프

#include<iostream>
#include<queue>

using namespace std;

int A, B;

bool visited[10001];

void BFS() {
	queue<pair<int, string>> q;
	q.push({ A,"" });
	visited[A] = true;

	while (!q.empty()) {
		int x = q.front().first;
		string s = q.front().second;
		q.pop();

		if (x == B) {
			cout << s << '\n';
			return;
		}

		int D = (2 * x) % 10000;

		if (!visited[D]) {
			visited[D] = true;
			q.push({ D,s + "D" });
		}

		int S;
		if (x == 0) {
			S = 9999;
		}
		else {
			S = x - 1;
		}

		if (!visited[S]) {
			visited[S] = true;
			q.push({ S,s + "S" });
		}

		int L = ((x % 1000) * 10) + (x / 1000);

		if (!visited[L]) {
			visited[L] = true;
			q.push({ L,s + "L" });
		}

		int R = (x / 10) + ((x % 10) * 1000);

		if (!visited[R]) {
			visited[R] = true;
			q.push({ R,s + "R" });
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> A >> B;

		for (int j = 0; j < 10001; j++) {
			visited[j] = false;
		}

		BFS();
	}

	return 0;
}