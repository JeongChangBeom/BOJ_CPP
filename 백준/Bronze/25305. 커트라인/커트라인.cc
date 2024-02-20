//boj25305번_커트라인_정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int x, int y) {
	return x > y;
}

int main() {
	int N, k;
	cin >> N >> k;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end(), compare);

	cout << v[k - 1];
}