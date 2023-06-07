//boj2504번_괄호의 값_자료구조(스택)

#include<iostream>
#include<stack>

using namespace std;

int main() {
	string str;
	cin >> str;

	stack<char> s;
	int result = 0;
	int num = 1;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
			num *= 2;
		}
		if (str[i] == ')') {
			if (s.empty() || s.top() != '(') { // <-
				cout << "0";
				return 0;
			}
			else {
				if (str[i - 1] == '(') {
					result += num;
				}
				s.pop();
				num /= 2;
			}
		}
		if (str[i] == '[') {
			s.push(str[i]);
			num *= 3;
		}
		if (str[i] == ']') {
			if (s.empty() || s.top() != '[') { // <-
				cout << "0";
				return 0;
			}
			else {
				if (str[i - 1] == '[') {
					result += num;
				}
				s.pop();
				num /= 3;
			}
		}
	}
	if (s.empty()) {
		cout << result;
	}
	else {
		cout << "0";
	}
}
//스택을 이용해서 풀 수 있는 문제. 처음에 런타임 에러(Segfault)가 났는데 이유는 top()함수를 사용하기 전에
//s.top() != '(' || s.empty() 이런식으로 작성하여 스택이 비어있는지 확인을 안했기 때문에 에러가 났다.
//그 후로 한번더 틀렸었는데 이유는 마지막에 result를 출력할때 스택이 비어 있지 않아도 출력했기 때문이다.
//(((((([] 같은 느낌의 문자열을 받아도 정상이라고 확인됐었는데 스택이 비어있는지 확인해 줌으로써 해결했다.