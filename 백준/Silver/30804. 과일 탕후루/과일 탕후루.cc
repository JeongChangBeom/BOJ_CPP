//boj30804번_과일 탕후루_두 포인터

#include<iostream>

using namespace std;

int kind[10];
int tang[200001];

int Count() {
	int cnt = 0;

	for (int i = 0; i < 10; i++) {
		if (kind[i] != 0) {
			cnt++;
		}
	}

	return cnt;
}

int main() {
	int N;
	cin >> N;
		
	for (int i = 0; i < N; i++) {
		cin >> tang[i];
	}

	int start = 0;
	int end = 0;

	int result = 0;

	while (start < N) {
		while (end < N) {
			kind[tang[end]]++;
			end++;

			if (Count() > 2) {
				end--;
				kind[tang[end]]--;

				break;
			}
		}
		result = max(result, end - start);

		kind[tang[start]]--;
		start++;
	}

	cout << result;

	return 0;
}