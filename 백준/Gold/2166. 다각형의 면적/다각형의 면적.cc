//boj2166번_다각형의 면적_수학

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct dot {
	double x;
	double y;
};

int main() {
	int N;
	cin >> N;

	vector<dot> v;

	for (int i = 0; i < N; i++) {
		double a, b;
		cin >> a >> b;

		dot d;
		d.x = a;
		d.y = b;

		v.push_back(d);
	}

	v.push_back(v.front());

	double result = 0;

	for (int i = 0; i < N; i++) {
		result += (v[i].x * v[i + 1].y) - (v[i + 1].x * v[i].y);
	}

	cout << fixed;
	cout.precision(1);

	cout << abs(result / 2.0);

	return 0;
}