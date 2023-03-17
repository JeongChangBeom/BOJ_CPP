//boj11651번_좌표 정렬하기2_정렬

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Point {
	int x;
	int y;
};

bool compare(Point a, Point b) {
	if (a.y < b.y) {
		return true;
	}
	else if (a.y == b.y) {
		if (a.x < b.x) {
			return true;
		}
	}
	return false;
}

int main() {
	vector<Point> point;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		Point p;
		cin >> p.x >> p.y;
		point.push_back(p);
	}

	sort(point.begin(), point.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << point[i].x << " " << point[i].y << "\n";
	}
}