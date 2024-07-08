//boj20923번_숫자 할리갈리 게임_구현

#include<iostream>
#include<deque>

using namespace std;

int N, M;

deque<int> dodo;
deque<int> dodo_ground;

deque<int> suyeon;
deque<int> suyeon_ground;

bool turn = false;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int card_do, card_su;
		cin >> card_do >> card_su;

		dodo.push_front(card_do);
		suyeon.push_front(card_su);
	}

	int count = 0;

	while (count < M) {
		if (!turn) {
			dodo_ground.push_front(dodo.front());
			dodo.pop_front();
		}
		else {
			suyeon_ground.push_front(suyeon.front());
			suyeon.pop_front();
		}

		if (dodo.size() == 0) {
			suyeon.push_back(1);
			break;
		}
		else if (suyeon.size() == 0) {
			dodo.push_back(1);
			break;
		}

		if ((!dodo_ground.empty() && !suyeon_ground.empty()) && (dodo_ground.front() + suyeon_ground.front()) == 5) {
			while (!dodo_ground.empty()) {
				suyeon.push_back(dodo_ground.back());
				dodo_ground.pop_back();
			}
			while (!suyeon_ground.empty()) {
				suyeon.push_back(suyeon_ground.back());
				suyeon_ground.pop_back();
			}
		}
		else if ((!dodo_ground.empty() && dodo_ground.front() == 5) || (!suyeon_ground.empty() && suyeon_ground.front() == 5)) {
			while (!suyeon_ground.empty()) {
				dodo.push_back(suyeon_ground.back());
				suyeon_ground.pop_back();
			}
			while (!dodo_ground.empty()) {
				dodo.push_back(dodo_ground.back());
				dodo_ground.pop_back();
			}
		}

		turn = !turn;
		count++;
	}

	if (dodo.size() > suyeon.size()) {
		cout << "do";
	}
	else if (dodo.size() < suyeon.size()) {
		cout << "su";
	}
	else {
		cout << "dosu";
	}

	return 0;
}