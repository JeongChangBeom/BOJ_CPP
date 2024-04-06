//boj1015번_수열 정렬_정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> A;
	vector<int> P(N);

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		A.push_back({ num,i });
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < N; i++) {
		P[A[i].second] = i;
	}

	for (int i = 0; i < N; i++) {
		cout << P[i] << " ";
	}
}