//boj4889번_안정적인 문자열_자료구조(스택)

#include<iostream>
#include<stack>

using namespace std;

int main() {
	int count = 1;

	while (true) {
		string str;
		cin >> str;

		if (str[0] == '-') {
			break;
		}

		stack<char> s;
		int result = 0;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '{') {
				s.push('{');
			}
			else if (str[i] == '}' && s.empty()) {
				s.push('{');
				result++;
			}
			else if (str[i] == '}' && !s.empty()) {
				s.pop();
			}
		}

		if (!s.empty()){
			result += s.size() / 2;
		}

		cout << count << ". " << result << '\n';
		count++;
	}
	return 0;
}