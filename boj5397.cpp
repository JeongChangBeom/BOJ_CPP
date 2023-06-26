//boj5397번_키로거_자료구조(스택)

#include<iostream>
#include<stack>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string L;
		cin >> L;

		stack<char> s1;
		stack<char> s2;

		for (int i = 0; i < L.size(); i++) {
			if (L[i] == '<') {
				if (s1.empty()) {
					continue;
				}
				else {
					s2.push(s1.top());
					s1.pop();
				}
			}
			else if(L[i] == '>') {
				if (s2.empty()) {
					continue;
				}
				else {
					s1.push(s2.top());
					s2.pop();
				}
			}
			else if (L[i] == '-') {
				if (s1.empty()) {
					continue;
				}
				else {
					s1.pop();
				}
			}
			else {
				s1.push(L[i]);
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

		cout << '\n';
	}
}
//스택을 이용해서 해결할 수 있는 문제.
//스택 2개를 사용해서 s1의 top을 커서로 생각하면 쉽게 해결 할 수 있다. 