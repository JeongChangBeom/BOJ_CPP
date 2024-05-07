//boj15903번_카드 합체 놀이_그리디 알고리즘

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<long long> v;

	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < m; i++) {
		sort(v.begin(), v.end());
		v[0] += v[1];
		v[1] = v[0];
	}

	long long result = 0;

	for (int i = 0; i < v.size(); i++) {
		result += v[i];
	}
	cout << result;
}
