//boj11286번_절댓값 힙_자료구조(우선순위 큐)

#include<iostream>
#include<queue>

using namespace std;

struct compare {
	bool operator()(int x, int y) {
		if (abs(x) == abs(y)) {
			return y < x;
		}
		else {
			return abs(y) < abs(x);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, compare> q;

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
//우선순위 큐의 형태가 priority_queue<자료형,구현체,비교 연산자> 임을 알아야 풀 수 있는 문제.
//구조체를 사용하여 비교 연산자 부분을 만들면 쉽게 해결할 수 있다.