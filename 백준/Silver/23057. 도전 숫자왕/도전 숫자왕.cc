//boj23057번_도전 숫자왕_브루트포스 알고리즘

#include<iostream>
#include<set>

using namespace std;

int N;
int arr[21];
set<int> sum;

void Solve(int count, int card) {
	sum.insert(card);

	if (count == N) {
		return;
	}

	Solve(count + 1, card + arr[count + 1]);
	Solve(count + 1, card);
}

int main() {
	cin >> N;

	int M = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		M += arr[i];
	}

	for (int i = 0; i < N; i++) {
		Solve(i, arr[i]);
	}

	cout << M - sum.size();

	return 0;
}