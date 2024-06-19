//boj11000번_강의실 배정_그리디 알고리즘

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct Class_Room {
	int start;
	int end;
};

bool compare(Class_Room x, Class_Room y) {
	if (x.start == y.start) {
		if (x.end < y.end) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (x.start < y.start) {
			return true;
		}
		else {
			return false;
		}
	}
}

int main() {
	int N;
	cin >> N;

	vector<Class_Room> v;

	for (int i = 0; i < N; i++) {
		Class_Room c;
		cin >> c.start >> c.end;
		v.push_back(c);
	}

	sort(v.begin(), v.end(), compare);

	priority_queue<int, vector<int>, greater<int>> q;
	q.push(v[0].end);

	for (int i = 1; i < v.size(); i++) {
		int start_time = v[i].start;
		int end_time = v[i].end;

		if (q.top() > start_time) {
			q.push(end_time);
		}
		else {
			q.pop();
			q.push(end_time);
		}
	}

	cout << q.size();

	return 0;
}
