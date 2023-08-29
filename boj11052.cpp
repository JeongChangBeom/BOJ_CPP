//boj11052번_카드 구매하기_dp

#include <iostream>

using namespace std;

int dp[1001];
int card[1001];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}

	dp[1] = card[1];

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}
	cout << dp[N];
}
//조건을 생각해보면 카드를 적게 비싼 가격으로 사는 것이 핵심이다.
//몇가지 경우의 수를 보면 1장을 살때 {1}, 2장을 살때 {1,1} / {2}, 3장을 살때 {1,1,1} / {1,2} / {3} 이라는 경우가 나온다. 
//이걸로 유추해 볼 수 있는 것은 사야되는 카드의 장수가 늘어날때 이전장수에 비해 경우의 수가 1개가 늘어나는 것을 알 수 있다.
//이 경우의 수 들 중에서 최대값을 구해서 dp[]에 저장하는 것이 문제 해결 방법이다.