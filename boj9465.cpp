//boj9465번_스티커_dp

#include<iostream>

using namespace std;

int arr1[100001];
int arr2[100001];
int dp1[100001];
int dp2[100001];

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		for (int j = 1; j <= N; j++) {
			cin >> arr1[j];
		}
		for (int j = 1; j <= N; j++) {
			cin >> arr2[j];
		}

		dp1[1] = arr1[1];
		dp2[1] = arr2[1];

		for (int j = 2; j <= N; j++) {
			dp1[j] = arr1[j] + max(dp2[j - 1], dp2[j - 2]);
			dp2[j] = arr2[j] + max(dp1[j - 1], dp1[j - 2]);
		}
		cout << max(dp1[N], dp2[N]) << "\n";
	}
}
//1년전에 java로 풀었던 dp문제라서 비교적 쉽게 풀 수 있었다.
//처음에 제출했는데 답은 맞는거 같은데 틀렸다고 나와서 많이 고민했는데
//원인은 답을 출력할 때 개행문자를 넣지 않은 것이였다...다음엔 문제를 더욱 꼼꼼히 봐야할것 같다.