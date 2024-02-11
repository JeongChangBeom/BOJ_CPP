//boj10810_공 넣기_구현

#include<iostream>

using namespace std;

int arr[102];

int main() {
	int N, M;
	cin >> N >> M;

	for (int x = 0; x < M; x++) {
		int i, j, k;
		cin >> i >> j >> k;
		for (int y = i; y <= j; y++) {
			arr[y] = k;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}
}
//구현문제.
//2중 for문으로 간단하게 바구니에 공을 넣으면 되는문제.
//이미 공이 들어있는 상황에서는 공을 빼고 넣는 것이므로 배열의 값을 k로 바꿔주는 것으로 쉽게 구현할 수 있다.