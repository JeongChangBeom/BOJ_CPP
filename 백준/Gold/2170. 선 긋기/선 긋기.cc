//boj2170번_선 긋기_정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct line {
	int start;
	int end;
};

bool compare(line a, line b) {
	if (a.start < b.start) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<line> v;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		line l;
		l.start = x;
		l.end = y;

		v.push_back(l);
	}

	sort(v.begin(), v.end(), compare);

	int s = v[0].start;
	int e = v[0].end;

	int result = 0;

	for (int i = 0; i < N; i++) {
		if (e < v[i].start) {
			result += e - s;

			s = v[i].start;
			e = v[i].end;
		}
		else {
			e = max(e, v[i].end);
		}
	}

	result += e - s;

	cout << result;

	return 0;
}