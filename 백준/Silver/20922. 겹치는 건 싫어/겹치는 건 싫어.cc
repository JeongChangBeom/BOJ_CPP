//boj20922번_겹치는 건 싫어_두 포인터

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int check[100001];

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	int result = -999;
	int i = 0;
	int j = 0;

	while (i <= j && j < N) {
		if (check[v[j]] < K) {
			check[v[j]]++;
			j++;
			result = max(result, j - i);
		}
		else {
			check[v[i]]--;
			i++;
		}
	}
	cout << result;
}