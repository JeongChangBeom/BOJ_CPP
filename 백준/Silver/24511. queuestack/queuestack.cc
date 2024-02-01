//boj24511번_queuestack_자료구조(덱)

#include<iostream>
#include<queue>

using namespace std;

int check[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	deque<int> d;
	int count = 0;

	for (int i = 0; i < N; i++) {
		cin >> check[i];
	}

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (check[i] == 0) {
			d.push_back(num);
		}
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		d.push_front(num);

		cout << d.back() << " ";
		d.pop_back();
	}

}
//덱을 이용한 문제.
//문제를 자세히 읽어보면 사실 스택에 들어있는 원소는 사용자의 입력에 의해 리턴될 수 없다는 것을 알 수 있다.
//그래서 큐에 입력이 들어올때만 생각해서 해결하면 쉽게 풀 수 있다.