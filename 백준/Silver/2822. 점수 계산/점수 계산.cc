//boj2822번_점수 계산_정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare_first(const pair<int, int>& x, const pair<int, int>& y) {
	return x.first > y.first;
}

int main() {

	vector<pair<int, int>> v;

	for (int i = 1; i <= 8; i++) {
		int num;
		cin >> num;

		v.push_back({ num,i });
	}

	sort(v.begin(), v.end(), compare_first);

	int sum = 0;
	vector<int> quiz_num;

	for (int i = 0; i < 5; i++) {
		sum += v[i].first;
		quiz_num.push_back(v[i].second);
	}

	cout << sum << '\n';

	sort(quiz_num.begin(), quiz_num.end());

	for (int i = 0; i < 5; i++) {
		cout << quiz_num[i] << ' ';
	}
}