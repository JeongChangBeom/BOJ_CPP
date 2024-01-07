#include <iostream>

using namespace std;

char arr[1000][1000];

int main()
{
	int N;
	bool first = false;
	int x = 0;
	int y = 0;
	int left_arm = 0;
	int right_arm = 0;
	int waist = 0;
	int waist_end = 0;
	int left_leg = 0;
	int right_leg = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char word;
			cin >> word;

			arr[i][j] = word;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == '*' && first == false) {
				x = i + 1 + 1;
				y = j + 1;
				first = true;
			}
		}
	}
	cout << x << " " << y << '\n';

	for (int i = 0; i < y - 1; i++) {
		if (arr[x - 1][i] == '*') {
			left_arm++;
		}
	}
	cout << left_arm << " ";

	for (int i = y; i < N; i++) {
		if (arr[x - 1][i] == '*') {
			right_arm++;
		}
	}
	cout << right_arm << " ";

	for (int i = x; i < N; i++) {
		if (arr[i][y - 1] == '*') {
			waist++;
			waist_end = i;
		}
	}
	cout << waist << " ";

	for (int i = N - 1; i > waist_end; i--) {
		if (arr[i][y - 2] == '*') {
			left_leg++;
		}
	}
	cout << left_leg << " ";

	for (int i = N - 1; i > waist_end; i--) {
		if (arr[i][y] == '*') {
			right_leg++;
		}
	}
	cout << right_leg;

}