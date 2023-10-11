//boj7662번_이중 우선순위 큐_자료구조

#include<iostream>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int  k;
		cin >> k;

		multiset<int> q;

		for (int i = 0; i < k; i++) {
			char oper;
			int num;

			cin >> oper >> num;

			switch (oper) {
			case 'I':
				q.insert(num);
				break;
			case 'D':
				if (num == 1 && !q.empty()) {
					std::multiset<int>::iterator it = q.end();
					it--;
					q.erase(it);
					break;
				}
				else if (num == -1 && !q.empty()) {
					q.erase(q.begin());
					break;
				}
			}
		}
		if (q.empty()) {
			cout << "EMPTY" << '\n';
		}
		else {
			std::multiset<int>::iterator it = q.end();
			it--;
			cout << *it << " " << *q.begin() << '\n';
		}
	}
}
//multiset을 이용해서 해결한 문제.
//multiset은 삽입한 값을 바로 정렬하므로 이문제를 푸는데 있어 적절했다.
//I를 입력받았을땐 삽입을 하고 D -1을 입력받았을땐 최소값(q.begin())을 삭제해주고,
//D 1을 입력받았을땐 최대값(q.end()는 최대값 + 1의 주소이므로 q.end()의 iterator값에 --를 해준다)을 삭제해주는 식으로 해결했다.
//마지막 출력에 개행문자를 빼먹어 어디서 틀린지 몰라 엄청 고민했었다. 이런 사소한 부분도 주의하자.