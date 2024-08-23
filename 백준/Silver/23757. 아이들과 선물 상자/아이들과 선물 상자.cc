//boj23757번_아이들과 선물 상자

#include<iostream>
#include<queue>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	priority_queue<int> q;

	for (int i = 0; i < N; i++) {
		int box;
		cin >> box;
		q.push(box);
	}

	bool check = false;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		if (q.top() >= num) {
			int temp = q.top() - num;
			q.pop();
			if (temp != 0) {
				q.push(temp);
			}
		}
		else {
			check = true;
		}
	}

	if (!check) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}