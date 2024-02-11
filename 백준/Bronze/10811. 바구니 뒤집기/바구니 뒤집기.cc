//boj10811번_바구니 뒤집기_구현

#include<iostream>
#include<algorithm>

using namespace std;

int arr[101];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}

	for (int x = 0; x < M; x++) {
		int i, j;
		cin >> i >> j;
		reverse(arr + i, arr + j + 1);
	}

	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}
}
//구현문제.
//입력받은 i~j사이의 바구니를 역순으로 바꾸는 문제이다.
//reverse함수를 사용해서 쉽게 해결했다.
