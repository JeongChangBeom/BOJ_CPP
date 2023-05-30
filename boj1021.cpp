//boj1021번_회전하는 큐_자료구조(덱)

#include<iostream>
#include<deque>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	deque<int> d;

	for (int i = 1; i <= N; i++) {
		d.push_back(i);
	}

	int left = 0;
	int right = 0;
	int result = 0;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		for (int i = 0; i < d.size(); i++) {
			if (d[i] == num) {
				left = i;
				right = d.size() - i;
				break;
			}
		}

		if (left <= right) {
			while (true) {
				if (d.front() == num) {
					d.pop_front();
					break;
				}
				d.push_back(d.front());
				d.pop_front();
				result++;
			}
		}
		else {
			while (true) {
				if (d.front() == num) {
					d.pop_front();
					break;
				}
				d.push_front(d.back());
				d.pop_back();
				result++;
			}
		}
	}
	cout << result;
}
//덱으로 원형큐를 구현하는 문제.
//현재 위치에서 왼쪽과 오른쪽 어느쪽이 더 가까운지 판단하는 것이 문제풀이의 핵심이다.