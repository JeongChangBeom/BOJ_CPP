//boj20055번_컨베이어 벨트 위의 로봇_구현

#include<iostream>
#include<deque>

using namespace std;

int N, K;
int cnt;
int result;

deque<bool> robot;
deque<int> belt;

void Solve_1() {
	robot.push_front(robot.back());
	robot.pop_back();

	belt.push_front(belt.back());
	belt.pop_back();

	if (robot[N - 1] == true) {
		robot[N - 1] = false;
	}
}

void Solve_2() {
	for (int i = N - 2; i >= 0; i--) {
		if (robot[i] && !robot[i + 1] && belt[i + 1] > 0) {
			robot[i] = false;
			robot[i + 1] = true;
			belt[i + 1]--;

			if (belt[i + 1] == 0) {
				cnt++;
			}
		}

		if (robot[N - 1] == true) {
			robot[N - 1] = false;
		}
	}
}

void Solve_3() {
	if (belt[0] > 0 && !robot[0]) {
		robot[0] = true;
		belt[0]--;

		if (belt[0] == 0) {
			cnt++;
		}
	}
}

int main() {
	cin >> N >> K;

	for (int i = 0; i < N * 2; i++) {
		int num;
		cin >> num;
		belt.push_back(num);
		robot.push_back(false);
	}

	while (true) {
		result++;

		Solve_1();
		Solve_2();
		Solve_3();

		if (cnt >= K) {
			cout << result;
			break;
		}
	}

	return 0;
}