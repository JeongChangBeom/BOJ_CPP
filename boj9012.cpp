//boj9012번_괄호_자료구조(스택)

#include<iostream>
#include<stack>

using namespace std;

int main() {
	int N;
	cin >> N;

	int j;

	for (int i = 0; i < N; i++) {
		stack<char> s;

		string x;
		cin >> x;

		for (j = 0; j < x.length(); j++) {
			if (x[j] == '(') {
				s.push(x[j]);
			}
			if (x[j] == ')') {
				if (s.empty() == false) {
					s.pop();
				}
				else {
					cout << "NO" << "\n";
					break;
				}
			}
		}

		if (s.empty() && j == x.length()) {
			cout << "YES" << "\n";
		}
		else if(s.empty() == false && j == x.length()) {
			cout << "NO" << "\n";
		}
	}
}
//자료구조 스택을 이용해서 풀 수 있는 문제. 풀다보니 코드가 조금 난잡해졌다.
//다음부턴 깔끔한 코드를 짤 수 있도록 좀 더 깊게 생각해봐야 될 것 같다.