//boj1966번_프린터 큐_자료구조(큐)

#include<iostream>
#include<queue>
#include<deque>
#include<algorithm>

using namespace std;

struct num {
	int number;
	int priority;
};

bool compare(int x, int y) { //내림차순 정렬
	return y < x;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;

		queue<num> q;
		deque<int> d; //우선순위 비교를 위한 덱

		for (int j = 0; j < N; j++) {
			int x;
			cin >> x;

			num n;
			n.number = j;
			n.priority = x;
			q.push(n);

			d.push_back(x);
		}

		sort(d.begin(), d.end(), compare); //우선순위가 높은 순으로 내림차순 정렬
		
		int count = 0;

		while(true) {
			if (q.front().priority == d.front()) {
				if (q.front().number == M) { //몇 번째로 인쇄되었는지 궁금한 문서가 우선순위가 가장 높을 경우
					count++;
					cout << count << "\n";
					break;
				}
				q.pop();
				d.pop_front();
				count++;
			}
			else { //우선순위가 제일 높은 문서가 아닐경우 큐의 가장 뒤에 재배치.
				num x = q.front();
				q.pop();
				q.push(x);
			}
		}
	}
}
//자료구조 큐를 이용해 풀 수 있는 문제.
//같은 문서라도 입력받은 순서에 따라 출력순서가 바뀌기 때문에 구조체를 
//이용하여 고유 번호를 만들어 해결했다.