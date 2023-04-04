//boj11659번_구간 합 구하기 4_구간 합

#include<iostream>

using namespace std;

int sum[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int num;
	cin >> num;

	sum[0] = 0;
	sum[1] = num;

	for (int i = 2; i <= N; i++) {
		cin >> num;
		sum[i] = sum[i - 1] + num;
	}

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		cout << sum[y] - sum[x-1] << "\n";
	}
}
//입력받은 모든 수를 for문으로 더하게 되면 시간초과가 나는 문제.
//위와 같이 풀었을 때도 처음엔 시간초과가 났는데 입출력가속을 해주니 통과되었다.