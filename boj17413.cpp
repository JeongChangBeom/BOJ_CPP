//boj17413번_단어 뒤집기 2_자료구조(스택)

#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	string str;
	getline(cin, str);

	stack<char> s;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '<') {
			if (!s.empty()) {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << '<';
				i++;
			}
			while (str[i] != '>') {
				cout << str[i++];
			}
			cout << '>';
		}
		else {
			s.push(str[i]);
			if (str[i] == ' ') {
				s.pop();
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ' ';
			}
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}
//스택을 사용해서 풀 수 있는 문제.