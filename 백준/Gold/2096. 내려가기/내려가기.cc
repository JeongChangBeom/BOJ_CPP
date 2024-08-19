//boj2096번_내려가기_슬라이딩 윈도우

#include<iostream>

using namespace std;

int dp_max[3];
int dp_min[3];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < 3; i++) {
		int num;
		cin >> num;

		dp_max[i] = num;
		dp_min[i] = num;
	}

	for (int i = 1; i < N; i++) {
		int num0, num1, num2;
		cin >> num0 >> num1 >> num2;

		int max0 = dp_max[0], max1 = dp_max[1], max2 = dp_max[2];
		int min0 = dp_min[0], min1 = dp_min[1], min2 = dp_min[2];


		dp_max[0] = num0 + max(max0, max1);
		dp_max[1] = num1 + max(max(max0, max1), max2);
		dp_max[2] = num2 + max(max1, max2);

		dp_min[0] = num0 + min(min0, min1);
		dp_min[1] = num1 + min(min(min0, min1), min2);
		dp_min[2] = num2 + min(min1, min2);
	}

	cout << max(max(dp_max[0], dp_max[1]), dp_max[2]) << " " << min(min(dp_min[0], dp_min[1]), dp_min[2]);
}