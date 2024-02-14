//boj11005번_진법 변환 2_구현

#include<iostream>
#include<stack>

using namespace std;

int main() {
	int N, B;
	cin >> N >> B;

	stack<char> s;

	while (N > 0) {
		if (N % B < 10) {
			s.push(N % B + '0');
		}
		else {
			s.push(N % B - 10 + 'A');
		}
		N /= B;
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}