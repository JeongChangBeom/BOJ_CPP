//boj4949번_균형잡힌 세상_자료구조(스택)

#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	while (true) {
		stack<char> s;

		string str;
		getline(cin, str);

		if (str[0] == '.' && str.length() == 1) {
			return 0;
		}

		int i;

		for (i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				s.push(str[i]);
			}
			if (str[i] == ')') {
				if (s.empty() == false && s.top() == '(') {
					s.pop();
				}
				else {
					cout << "no" << "\n";
					break;
				}
			}
			if (str[i] == ']') {
				if (s.empty() == false && s.top() == '[') {
					s.pop();
				}
				else {
					cout << "no" << "\n";
					break;
				}
			}
		}

		if (s.empty() && i == str.length()) {
			cout << "yes" << "\n";
		}
		else if(s.empty() == false && i== str.length()){
			cout << "no" << "\n";
		}
	}
}
//자료구조 스택을 사용해서 풀 수 있는 문제.
//getline()을 통해 공백까지 입력받는 것을 놓치면 틀릴 수도 있는 문제였다.