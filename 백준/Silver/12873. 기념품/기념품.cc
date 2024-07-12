//boj12873번_기념품_자료구조(큐)

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

	long long num = 1;
	long long t = 1;

	while(q.size() != 1) {
		num = (t * t * t - 1) % q.size();

		for (int i = 0; i < num; i++) {
			q.push(q.front());
			q.pop();
		}
		q.pop();
		t++;
	}

	cout << q.front();

	return 0;
}