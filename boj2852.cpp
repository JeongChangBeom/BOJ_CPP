//boj2852번_NBA 농구_구현, 문자열

#include<iostream>
#include<string>

using namespace std;

int main() {
	int N;
	cin >> N;

	int team;
	string time;

	int score_A = 0;
	int	score_B = 0;

	int time_A = 0;
	int time_B = 0;

	int time_cur = 0;

	for (int i = 0; i < N; i++) {
		cin >> team >> time;

		int m = stoi(time.substr(0, 2));
		int s = stoi(time.substr(3, 2));

		if (score_A > score_B) {
			time_A += (m * 60) + s - time_cur;
		}
		else if(score_A < score_B) {
			time_B += (m * 60) + s - time_cur;
		}

		if (team == 1) {
			score_A++;
		}
		else {
			score_B++;
		}
		time_cur = (m * 60) + s;
	}

	if (score_A > score_B) {
		time_A += (48 * 60) - time_cur;
	}
	else if (score_A < score_B) {
		time_B += (48 * 60) - time_cur;
	}

	cout.width(2);
	cout.fill('0');

	cout << time_A / 60;

	cout << ":";

	cout.width(2);
	cout.fill('0');

	cout << time_A % 60 << '\n';

	cout.width(2);
	cout.fill('0');

	cout << time_B / 60;

	cout << ":";

	cout.width(2);
	cout.fill('0');

	cout << time_B % 60 << '\n';

}