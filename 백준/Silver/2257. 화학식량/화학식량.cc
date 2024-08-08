//boj2257번_화학식량_자료구조(스택)

#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;

	stack<string> s;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'H') {
			s.push("1");
		}
		else if (str[i] == 'C') {
			s.push("12");
		}
		else if (str[i] == 'O') {
			s.push("16");
		}
		else if (str[i] == '(') {
			s.push("(");
		}
		else if (str[i] == ')') {
			int num = 0;

			while (s.top() != "(") {
				num += stoi(s.top());
				s.pop();
			}

			s.pop();
			s.push(to_string(num));
		}
		else if (str[i] >= '2' && str[i] <= '9') {
			int num = stoi(s.top());
			s.pop();
			s.push(to_string(num * (str[i] - '0')));
		}
	}

	int result = 0;

	while (!s.empty()) {
		result += stoi(s.top());
		s.pop();
	}

	cout << result;

	return 0;
}