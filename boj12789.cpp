//boj12789번_도키도키 간식드리미_자료구조(스택, 큐)

#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main() {
	int N;
	cin >> N;

	queue<int> q;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		q.push(num);
	}

	stack<int> s;
	int turn = 1;

	while (!q.empty()) {
		if (q.front() == turn) {
			q.pop();
			turn++;
		}
		else{
			if (!s.empty() && s.top() == turn) {
				s.pop();
				turn++;
			}
			else {
				s.push(q.front());
				q.pop();
			}
		}
	}

	while(!s.empty()) {
		if (s.top() != turn) {
			cout << "Sad";
			return 0;
		}
		s.pop();
		turn++;
	}
	cout << "Nice";
}
//스택과 큐를 활용해서 풀 수 있는 문제. 문제가 요구하는대로 처음 서있는 순서대로 큐에 넣고
//차례가 아니면 스택에 넣어놨다가 pop하면서 순서가 맞는지 확인하면된다.