//boj15828번_Router_큐

#include<iostream>
#include<queue>

using namespace std;

int main() {
	int N;
	cin >> N;

	queue<int> q;

	while (true) {
		int info;
		cin >> info;

		if (info == -1) {
			break;
		}

		if (!q.empty() && info == 0) {
			q.pop();
		}

		if (info > 0) {
			if (q.size() >= N) {
				continue;
			}
			else {
				q.push(info);
			}
		}
	}

	if (q.empty()) {
		cout << "empty";
	}
	else {
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
	}

	return 0;
}