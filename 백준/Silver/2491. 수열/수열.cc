//boj2491번_수열_구현

#include<iostream>

using namespace std;

int arr[100001];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	int result = 1;
	int length_up = 1;
	int length_down = 1;

	for (int i = 1; i < N; i++) {
		if (arr[i] <= arr[i + 1]) {
			length_up++;
		}
		else {
			length_up = 1;
		}

		if (arr[i] >= arr[i + 1]) {
			length_down++;
		}
		else {
			length_down = 1;
		}

		result = max(max(length_up, length_down), result);
	}
	cout << result;
}
//구현문제.
//수열이 커질때, 작아질때의 길이를 구해서 최대값을 갱신해주면되는 간단한 문제.