//boj2309번_일곱 난쟁이_정렬, 브루트포스 알고리즘

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int arr[10];
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + 9);

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (arr[i] + arr[j]) == 100) {
				arr[i] = 999;
				arr[j] = 999;
				break;
			}
		}
		if (arr[i] == 999) { // <- 이부분이 없으면 7명이 안될 수 있음.
			break;
		}
	}

	for (int i = 0; i < 9; i++) {
		if (arr[i] < 100) {
			cout << arr[i] << "\n";
		}
	}
}
//2중 for문으로 모든 경우를 해보면 풀 수 있는문제.
//주석에 표시해둔 조건문을 생각을 못해 엄청 헤맸었다.