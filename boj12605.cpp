//boj12605번_단어순서 뒤집기_자료구조

#include<iostream>
#include<sstream>
#include<stack>
#include<vector>

using namespace std;

stack<string> split(string input, char delimiter) {
	stack<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push(temp);
	}

	return answer;
}

int main() {
	int N;
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);

		stack<string> s = split(str, ' ');

		cout << "Case #" << i+1 << ": ";

		while (s.empty() == false) {
			cout << s.top() << " ";
			s.pop();
		}

		cout << "\n";
	}
}
//문자열 split을 이용한 자료구조(스택)문제