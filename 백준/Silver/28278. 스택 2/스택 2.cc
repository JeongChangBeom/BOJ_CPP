//boj28278번_스택 2_자료구조(스택)

#include<iostream>
#include<stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	stack<int> s;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num == 1) {
			int x;
			cin >> x;

			s.push(x);
		}
		
		if (num == 2) {
			if (!s.empty()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else {
				cout << "-1" << '\n';
			}
		}
		
		if (num == 3) {
			cout << s.size() << '\n';
		}

		if (num == 4) {
			if (s.empty()) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}

		if (num == 5) {
			if (!s.empty()) {
				cout << s.top() << '\n';
			}
			else {
				cout << "-1" << '\n';
			}
		}
	}
}
//스택문제.
//스택의 원리를 아는지 확인하는 기초 문제. STL을 알면 쉽게 풀 수 있다.