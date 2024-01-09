//boj1205번_등수 구하기_구현

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int x, int y) {
	return x > y;
}

int main() {
	int N;
	int new_score;
	int P;
	int rank = 1;

	cin >> N >> new_score >> P;

	if (N == 0) {
		cout << "1";
		return 0;
	}

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int score;
		cin >> score;

		v.push_back(score);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		if (v[i] > new_score) {
			rank++;
		}
	}

	if (N == P && v[N - 1] >= new_score) {
		cout << "-1";
		return 0;
	}

	cout << rank;
}