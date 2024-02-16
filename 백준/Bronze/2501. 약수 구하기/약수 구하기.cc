//boj2501번_약수 구하기_수학

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v;

	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			v.push_back(i);
		}
	}

	sort(v.begin(), v.end());

	cout << v[K - 1];
}