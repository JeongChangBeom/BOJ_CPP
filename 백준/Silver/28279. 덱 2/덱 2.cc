//boj28279번_덱 2_자료구조(덱)

#include<iostream>
#include<deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	deque<int> d;

	for (int i = 0; i < N; i++) {
		int cmd;
		cin >> cmd;

		if (cmd == 1) {
			int X;
			cin >> X;
			d.push_front(X);
		}
		else if (cmd == 2) {
			int X;
			cin >> X;
			d.push_back(X);
		}
		else if (cmd == 3) {
			if (!d.empty()) {
				cout << d.front() << '\n';
				d.pop_front();
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (cmd == 4) {
			if (!d.empty()) {
				cout << d.back() << '\n';
				d.pop_back();
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (cmd == 5) {
			cout << d.size() << '\n';
		}
		else if (cmd == 6) {
			if (d.empty()) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
		else if (cmd == 7) {
			if (!d.empty()) {
				cout << d.front() << '\n';
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (cmd == 8) {
			if (!d.empty()) {
				cout << d.back() << '\n';
			}
			else {
				cout << "-1" << '\n';
			}
		}
	}
}
//덱의 기초활용법을 다루는 문제.