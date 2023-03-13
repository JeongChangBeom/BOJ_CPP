//boj10773_제로_자료구조(스택)

#include<iostream>
#include<stack>

using namespace std;

int main() {
	int K;
	cin >> K;

	stack<int> s;

	for (int i = 0; i < K; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			s.pop();
		}
		else {
			s.push(x);
		}
	}

	int result = 0;
	while (s.empty() == false) {
		result += s.top();
		s.pop();
	}

	cout << result;
}
//스택을 이용해서 풀 수 있는 쉬운 문제.