//boj1138번_한 줄로 서기_구현

#include<iostream>

using namespace std;

int arr[10];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i < N + 1; i++) {
		int count;
		cin >> count;

		for (int j = 0; j < N; j++) {
			if (arr[j] == 0 && count == 0) {
				arr[j] = i;
				break;
			}
			else if (arr[j] == 0 && count != 0) {
				count--;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	
	return 0;
}
//구현 문제. 그리디 알고리즘 같은 느낌으로 풀 수 있었다.
//키가 작은 순서 대로(i = 1 부터) 왼쪽에 자기보다 큰 사람의 수를 입력받았을 때, 사람이 안서있으면서
//왼쪽에 서있는 사람의 수가 만족될 때 줄을 세우는 식으로 해결했다.