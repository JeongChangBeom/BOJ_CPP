//boj10799번_쇠막대기_자료구조(스택)

#include<iostream>
#include<stack>

using namespace std;

int main() {
	string str;
	cin >> str;

	int result = 0;

	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			if (str[i - 1] == '(') {
				s.pop();
				result += s.size();
			}
			else {
				s.pop();
				result++;
			}
		}
	}

	cout << result;
}
//자료구조 스택을 이용해 쉽게 해결할 수 있는 문제.