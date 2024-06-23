//boj4307번_개미_애드 혹

#include<iostream>
#include<vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int l, n;
		cin >> l >> n;

		vector<int> v;

		for (int i = 0; i < n; i++) {
			int ant;
			cin >> ant;
			v.push_back(ant);
		}

		int Time_max = 0;
		int Time_min = 0;

		for (int i = 0; i < v.size(); i++) {
			int dis_long = max(v[i], l - v[i]);
			int dis_short = min(v[i], l - v[i]);

			Time_max = max(Time_max, dis_long);
			Time_min = max(Time_min, dis_short);
		}

		cout << Time_min << " " << Time_max << '\n';
	}

	return 0;
}