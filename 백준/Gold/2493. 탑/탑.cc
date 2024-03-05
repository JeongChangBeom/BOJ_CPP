//boj2493번_탑_자료구조(스택)

#include<iostream>
#include<stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	stack<pair<int,int>> s;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		while (!s.empty()) {
			if (num < s.top().second) {
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}
		if (s.empty()) {
			cout << "0" << " ";
		}
		s.push({ i + 1,num });
	}
}