//boj2003번_수들의 합 2_투 포인터

#include <iostream>

using namespace std;

int arr[10001];
int result;
int sum;

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			sum += arr[j];

			if (sum == M) {
				result++;
				sum = 0;
				break;
			}
		}
		sum = 0;
	}

	cout << result;

	return 0;
}
//투 포인터의 가장 기초문제. 하나의 배열을 순차적으로 돌때 2개의 포인터의 위치를 기록하면서 접근하는 것이 핵심이다.