//boj2161번_카드 1_큐

#include<iostream>
#include<queue>

using namespace std;

int main() {
	int N;
	cin >> N;

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	
	while (q.size() != 1) {
		cout << q.front() << " ";
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front();
}
//기본적인 큐 문제