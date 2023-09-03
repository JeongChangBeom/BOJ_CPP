//boj11441번_합 구하기_누적 합

#include<iostream>

using namespace std;

int arr[100001];

int main() {
	ios_base::sync_with_stdio(0); //입출력가속
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int sum = 0;

	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;

		sum += num;

		arr[i] = sum;
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;

		cout << arr[y] - arr[x - 1] << '\n';
	}
}
//누적 합으로 풀 수 있는 문제. 누적 합으로 풀지 않으면 시간 초과가 나고, 누적 합으로 풀어도 입출력가속을 안해주면 시간초과가 나는 문제.