//boj25918번_북극곰은 괄호를 찢어_스택

#include<iostream>
#include<stack>

using namespace std;

int main() {
	int N;
	string str;

	cin >> N;
	cin >> str;

	stack<int> s;

	int result = 0;

	for (int i = 0; i < N; i++) {
		if (s.empty()) {
			s.push(str[i]);
		}
		else {
			if (str[i] == '(' && s.top() == ')') {
				s.pop();
			}
			else if (str[i] == ')' && s.top() == '(') {
				s.pop();
			}
			else {
				s.push(str[i]);
			}
		}
		result = max(result, (int)s.size());
	}

	if (s.empty()) {
		cout << result;
	}
	else {
		cout << -1;
	}
}