//boj2346번_풍선 터뜨리기_자료구조(덱)

#include<iostream>
#include<deque>

using namespace std;

struct number {
	int x;
	int index;
};

int main() {
	int N;
	cin >> N;

	deque<number> d;

	for (int i = 1; i <= N; i++) {
		number n;

		int num;
		cin >> num;

		n.x = num;
		n.index = i;

		d.push_back(n);
	}

	while (!d.empty()) {
		int x = d[0].x;
		cout << d[0].index << " ";

		d.pop_front();

		if (d.empty()) {
			break;
		}

		if (x > 0) {
			for (int i = 1; i < x; i++) {
				d.push_back(d[0]);
				d.pop_front();
			}
		}
		else {
			for (int i = 0; i < abs(x); i++) {
				d.push_front(d[d.size() - 1]);
				d.pop_back();
			}
		}

	}
}
//자료구조 덱을 이용한 문제. 구조체 덱을 사용해서 입력받은 수의 인덱스를 저장하고 덱의 특성을 이용해서 해결할 수 있었다.