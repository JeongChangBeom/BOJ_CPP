//boj14235번_크리스마스 선물_자료구조(우선순위 큐)

#include<iostream>
#include<queue>

using namespace std;

int main() {
	int N;
	cin >> N;

	priority_queue<int> pq;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		
		if (a == 0) {
			if (pq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			for (int j = 0; j < a; j++) {
				int gift;
				cin >> gift;

				pq.push(gift);
			}
		}
	}

	return 0;
}