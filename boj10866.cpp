//boj10828번_스택_자료구조(덱)

#include<iostream>
#include<deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> d;

	int  N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "push_front") {
			int x;
			cin >> x;
			d.push_front(x);
		}
		else if (str == "push_back") {
			int x;
			cin >> x;
			d.push_back(x);
		}
		else if (str == "pop_front") {
			if (d.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (d.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (str == "size") {
			cout << d.size() << "\n";
		}
		else if (str == "empty") {
			if (d.empty()) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (str == "front") {
			if (d.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << d.front() << "\n";
			}
		}
		else if (str == "back") {
			if (d.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << d.back() << "\n";
			}
		}
	}
}
//자료구조 덱의 기초 사용법을 다루는 문제.