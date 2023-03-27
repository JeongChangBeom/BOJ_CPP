//boj11399번_ATM_정렬

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct people {
	int num;
	int time;
};

bool compare(people x, people y) {
	if (x.time < y.time) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int N;
	cin >> N;

	vector<people> v;

	for (int i = 1; i <= N; i++) {
		people p;
		p.num = i;
		cin >> p.time;
		v.push_back(p);
	}

	sort(v.begin(), v.end(), compare);

	int result = 0;
	int sum = 0;

	for (int i = 0; i < v.size(); i++) {
		sum += v[i].time;
		result += sum;
	}

	cout << result;
}
//걸리는 시간이 짧은 사람이 먼저 줄을 서면 최종적으로 걸리는 시간이 짧다.
//그러므로 시간이 짧은 순으로 정렬해서 시간을 더해주면 되는 문제.