//boj1063번_킹_구현

#include<iostream>

using namespace std;


int dx[8] = { 1,-1,0,0,1,-1,1,-1 };
int dy[8] = { 0,0,-1,1,1,1,-1,-1 };

int main() {
	char kX, rX;

	int kingX = 0, kingY;
	int rockX = 0, rockY;

	cin >> kX >> kingY;
	cin >> rX >> rockY;

	if (kX == 'A') {
		kingX = 1;
	}
	else if (kX == 'B') {
		kingX = 2;
	}
	else if (kX == 'C') {
		kingX = 3;
	}
	else if (kX == 'D') {
		kingX = 4;
	}
	else if (kX == 'E') {
		kingX = 5;
	}
	else if (kX == 'F') {
		kingX = 6;
	}
	else if (kX == 'G') {
		kingX = 7;
	}
	else if (kX == 'H') {
		kingX = 8;
	}

	if (rX == 'A') {
		rockX = 1;
	}
	else if (rX == 'B') {
		rockX = 2;
	}
	else if (rX == 'C') {
		rockX = 3;
	}
	else if (rX == 'D') {
		rockX = 4;
	}
	else if (rX == 'E') {
		rockX = 5;
	}
	else if (rX == 'F') {
		rockX = 6;
	}
	else if (rX == 'G') {
		rockX = 7;
	}
	else if (rX == 'H') {
		rockX = 8;
	}

	int N;
	cin >> N;

	int dir = 0;

	for (int i = 0; i < N; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "R") {
			dir = 0;
		}
		else if (cmd == "L") {
			dir = 1;
		}
		else if (cmd == "B") {
			dir = 2;
		}
		else if (cmd == "T") {
			dir = 3;
		}
		else if (cmd == "RT") {
			dir = 4;
		}
		else if (cmd == "LT") {
			dir = 5;
		}
		else if (cmd == "RB") {
			dir = 6;
		}
		else if (cmd == "LB") {
			dir = 7;
		}

		int next_kingX = kingX + dx[dir];
		int next_kingY = kingY + dy[dir];

		if (next_kingX > 0 && next_kingX <= 8 && next_kingY > 0 && next_kingY <= 8) {
			if (next_kingX == rockX && next_kingY == rockY) {
				int next_rockX = rockX + dx[dir];
				int next_rockY = rockY + dy[dir];

				if (next_rockX > 0 && next_rockX <= 8 && next_rockY > 0 && next_rockY <= 8) {
					rockX = next_rockX;
					rockY = next_rockY;

					kingX = next_kingX;
					kingY = next_kingY;
				}
			}
			else {
				kingX = next_kingX;
				kingY = next_kingY;
			}
			
		}
	}

	cout << (char)(kingX + '@') << kingY << '\n';
	cout << (char)(rockX + '@') << rockY;

	return 0;
}