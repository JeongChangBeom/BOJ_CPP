//boj15565번_귀여운 라이언_두 포인터

#include<iostream>

using namespace std;

int arr[1000001];

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;
	int lion = 0;
	int result = 9999999;

	while (end <= N + 1) {
		if (lion < K) {
			if (arr[end] == 1) {
				lion++;
			}
			end++;
		}
		else if (lion == K) {
			result = min(result, end - start);

			if (arr[start] == 1) {
				lion--;
			}
			start++;
		}
		else {
			if (arr[start] == 1) {
				lion--;
			}
			start;
		}
	}
	if (result == 9999999) {
		cout << -1;
	}
	else {
		cout << result;
	}

	return 0;
}