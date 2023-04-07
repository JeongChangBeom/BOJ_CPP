//boj1927번_최소 힙_자료구조(우선순위 큐)

#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (q.empty()) {
				cout << "0" << "\n";
			}
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else {
			q.push(x);
		}
	}
}
//최근에 풀었던 최대 힙 문제를 최소 힙으로 만 바꾸면 되는 문제.
//우선순위큐는 기본적으로 트리의 맨위가 제일 큰수인데 greater를 이용해서
//맨위를 제일 작은수로 정렬하면 쉽게 해결할 수 있다.