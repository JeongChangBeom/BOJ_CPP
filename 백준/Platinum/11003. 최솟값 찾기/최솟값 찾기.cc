//boj11003번_최솟값 찾기_덱

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	deque<pair<int, int>> d;

	vector<int> result;

	for (int i = 0; i < N; i++) {
		if (!d.empty() && d.front().second < i - L + 1) {
			d.pop_front();
		}

		while (!d.empty() && d.back().first > v[i]) {
			d.pop_back();
		}

		d.push_back({ v[i],i });
		result.push_back(d.front().first);
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}