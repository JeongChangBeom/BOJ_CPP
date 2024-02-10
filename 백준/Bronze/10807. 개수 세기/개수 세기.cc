//boj10807번_개수 세기_구현

#include<iostream>

using namespace std;

int arr[201];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr[num + 100]++;
	}

	int v;
	cin >> v;

	cout << arr[v + 100];
}