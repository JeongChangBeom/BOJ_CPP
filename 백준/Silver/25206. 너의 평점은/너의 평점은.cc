//boj25206번_너의 평점은_구현

#include<iostream>

using namespace std;

int main() {
	double result = 0;
	double score_sum = 0;

	for (int i = 0; i < 20; i++) {
		string name;
		double score;
		string grade;
		cin >> name >> score >> grade;

		score_sum += score;

		if (grade == "A+") {
			result += score * 4.5;
		}
		if (grade == "A0") {
			result += score * 4.0;
		}
		if (grade == "B+") {
			result += score * 3.5;
		}
		if (grade == "B0") {
			result += score * 3.0;
		}
		if (grade == "C+") {
			result += score * 2.5;
		}
		if (grade == "C0") {
			result += score * 2.0;
		}
		if (grade == "D+") {
			result += score * 1.5;
		}
		if (grade == "D0") {
			result += score * 1.0;
		}
		if (grade == "F") {
			continue;
		}
		if (grade == "P") {
			score_sum -= score;
		}
	}

	cout << fixed;
	cout.precision(6);

	cout << result / score_sum;
}