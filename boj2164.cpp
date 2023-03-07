//boj2164번_카드2_큐

#include<iostream>
#include<queue>

using namespace std;

int main() {
	int N;
	cin >> N;

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	/*while (true) { <-답은 나오는데 백준에서 런타임 에러(Segfault)가 나옴
		q.pop();
		int x = q.front();
		q.pop();
		q.push(x);

		if (q.size() == 1) {
			cout << q.front();
		}
	}*/

	while (q.size() > 1) {
		q.pop();
		int x = q.front();
		q.pop();
		q.push(x);
	}

	cout << q.front();
}
//자료구조인 큐를 알고 있으면 쉽게 풀 수 있는 문제.
//다시 생각해보니 주석처리된 while문은 무한루프이기 때문에 N이 1로 입력되면 한번은 
//루프를 돌게 되어 빈큐에 q.front()를 하기 때문에 런타임 에러가 나는 것 같다.