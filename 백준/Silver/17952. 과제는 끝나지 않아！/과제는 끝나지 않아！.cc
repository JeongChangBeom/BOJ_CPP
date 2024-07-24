//boj17952번_과제는 끝나지 않아!_자료구조(스택)

#include<iostream>
#include<stack>

using namespace std;

struct Task {
	int s;
	int m;
};

int main() {
	int N;
	cin >> N;

	stack<Task> s;
	int result = 0;

	for (int i = 0; i < N; i++) {
		int cmd;
		cin >> cmd;

		if (cmd == 0) {
			if (!s.empty()) {
				s.top().m--;
				if (s.top().m == 0) {
					result += s.top().s;
					s.pop();
				}
			}
		}
		else if (cmd == 1) {
			int score, min;
			cin >> score >> min;

			Task T;
			T.s = score;
			T.m = min;

			s.push(T);

			s.top().m--;
			if (s.top().m == 0) {
				result += s.top().s;
				s.pop();
			}
		}
	}

	cout << result;

	return 0;
}