//boj10828번_스택_자료구조(스택)

#include<iostream>
#include<stack>

using namespace std;

int main() {
	stack<int> s;

	int  N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "push") {
			int x;
			cin >> x;
			s.push(x);
		}
		else if (str == "pop") {
			if (s.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (str == "size") {
			cout << s.size() << "\n";
		}
		else if (str == "empty") {
			if (s.empty()) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (str == "top") {
			if (s.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << s.top() << "\n";
			}
		}
	}
}
//자료구조 스택의 기초 사용법을 다루는 문제.