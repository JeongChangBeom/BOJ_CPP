//boj1924번_2007년_수학,구현

#include <iostream>

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;

	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	string day[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

	int date = 0;
	for (int i = 0; i < x - 1; i++) {
		date += month[i];
	}
	date += y;

	switch (date % 7) {
	case 1:
		cout << day[0] << "\n";
		break;
	case 2:
		cout << day[1] << "\n";
		break;
	case 3:
		cout << day[2] << "\n";
		break;
	case 4:
		cout << day[3] << "\n";
		break;
	case 5:
		cout << day[4] << "\n";
		break;
	case 6:
		cout << day[5] << "\n";
		break;
	case 0:
		cout << day[6] << "\n";
		break;
	}
	return 0;
}
//간단한 구현 문제. 문제자체는 어렵지 않지만 정해진 틀이 없는 구현문제라 생각을 잘해야 하는 문제.
//1월 1일부터 며칠이 지났는지 date에 더하여 그 값을 7로 나눈 나머지를 통해 무슨 요일인지 알 수 있다.
