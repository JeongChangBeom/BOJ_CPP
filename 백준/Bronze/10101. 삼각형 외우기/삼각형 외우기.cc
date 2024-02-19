//boj10101번_삼각형 외우기_구현

#include<iostream>

using namespace std;

int main() {
	int angle1, angle2, angle3;
	cin >> angle1 >> angle2 >> angle3;

	if (angle1 == 60 && angle2 == 60 && angle3 == 60) {
		cout << "Equilateral";
	}

	else if (angle1 + angle2 + angle3 == 180 && (angle1 == angle2 || angle2 == angle3 || angle3 == angle1)) {
		cout << "Isosceles";
	}

	else if (angle1 + angle2 + angle3 == 180 && (angle1 != angle2 && angle2 != angle3 && angle3 != angle1)) {
		cout << "Scalene";
	}
	else if (angle1 + angle2 + angle3 != 180) {
		cout << "Error";
	}
}