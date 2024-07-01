//boj1715번_카드 정렬하기_우선순위 큐

#include<iostream>
#include<queue>

using namespace std;

int main() {
	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		q.push(num);
	}

	int result = 0;

	while (true) {
		if (q.size() == 1) {
			break;
		}

		int A = q.top();
		q.pop();

		int B = q.top();
		q.pop();

		q.push(A + B);
		result += (A + B);
	}

	cout << result;

	return 0;
}