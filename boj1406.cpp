//boj1406번_에디터_자료구조(스택)

#include<iostream>
#include<stack>

using namespace std;

int main() {
	string str;
	cin >> str;

	stack<char> s1;
	stack<char> s2;

	for (int i = 0; i < str.size(); i++) {
		s1.push(str[i]);
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		char cmd;
		cin >> cmd;

		switch (cmd) {
		case 'L':
			if (s1.empty()) {
				break;
			}
			else {
				s2.push(s1.top());
				s1.pop();
				break;
			}
		case 'D':
			if (s2.empty()) {
				break;
			}
			else {
				s1.push(s2.top());
				s2.pop();
				break;
			}
		case 'B':
			if (s1.empty()) {
				break;
			}
			else {
				s1.pop();
				break;
			}
		case 'P':
			char x;
			cin >> x;
			s1.push(x);
		}
	}
	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
	while (!s2.empty()) {
		cout << s2.top();
		s2.pop();
	}
}
//스택을 이용해서 문제에 주어진 조건을 구현했다.
//스택을 2개 사용해서 첫번째 스택의 top을 편집기의 '커서'역할로 사용 하는 것이 핵심이다.