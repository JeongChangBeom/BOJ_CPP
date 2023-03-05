//boj1932번_정수 삼각형_dp

#include <iostream>
#include <algorithm>

using namespace std;

int dp[501][501];
int tri[501][501];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	dp[1][1] = tri[1][1];

	for (int i = 2; i <= N; i++) { // 이전층의 왼쪽 대각선과 오른쪽 대각선에서 가장 큰 값을 찾아 현재 트리 값을 더하는 식으로 계산
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j]; 
		}
	}

	int result = -1;
	for (int i = 1; i <= N; i++) {
		result = max(result, dp[N][i]);
	}

	cout << result << endl;

	return 0;
}
//바텀업 방식을 이용하여 풀 수 있는 문제