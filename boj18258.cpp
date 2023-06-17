//boj18258번_큐2_자료구조(큐)

#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); //입출력가속
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;

	int  N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (str == "pop") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (str == "size") {
			cout << q.size() << "\n";
		}
		else if (str == "empty") {
			if (q.empty()) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (str == "front") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (str == "back") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
	}
}
//자료구조 큐의 사용법을 알고 있으면 쉽게 해결할 수 있는문제. 입출력가속이 없으면 시간초과가 나온다.