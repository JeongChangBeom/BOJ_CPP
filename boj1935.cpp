//boj1935번_후위표기식2_자료구조(스택)

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
	stack<double> s;

	int N;
	cin >> N;

	string str;
	cin >> str;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < str.size(); i++) {
		if ((str[i] < 'A' || str[i] > 'Z') && !s.empty()) {
			double x = s.top();

			s.pop();
			switch (str[i]) {
			case '+':
				x = s.top() + x;
				break;
			case '-':
				x = s.top() - x;
				break;
			case '*':
				x = s.top() * x;
				break;
			case '/':
				x = s.top() / x;
				break;
			}
			s.pop();

			s.push(x);
		}
		else {
			s.push(v[str[i] - 'A']);
		}
	}
	cout << fixed;
	cout.precision(2);

	cout << s.top();
}