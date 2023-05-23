//boj1874번_스택 수열_자료구조(스택)

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	stack<int> s;
	vector<char> v;

	int num = 1;

	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;

		while (num <= x) {
			v.push_back('+');
			s.push(num);
			num++;
		}
		if (x == s.top()) {
			s.pop();
			v.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}
//스택을 사용해서 풀 수 있는 문제. num부터 입력받은 수까지 push한 후 입력받은 수와 스택의 top이
//같을 때 pop해주면된다. 그리고 입력받은 수가 스택의 top보다 클경우 수열을 만들 수 없다.