//boj17266번_어두운 굴다리_이분 탐색

#include<iostream>

using namespace std;

int arr[100001];

int main() {
	int N, M;
	cin >> N;
	cin >> M;

	for (int i = 1; i <= M; i++) {
		cin >> arr[i];
	}

	int start = 0;
	int end = 100000;

	int result = 999999;

	while (start <= end) {
		bool check = true;
		int mid = (start + end) / 2;

		if (arr[1] > mid) {
			check = false;
		}

		for (int i = 1; i <= M - 1; i++) {
			if (arr[i + 1] - arr[i] > mid * 2) {
				check = false;
				break;
			}
		}

		if (N - arr[M] > mid) {
			check = false;
		}

		if (check) {
			result = min(result, mid);
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	cout << result;
}
//이분탐색을 이용해서 풀 수 있는문제.
//처음부터 첫번째 가로등까지, 가로등과 가로등 사이, 마지막 가로등과 끝으로 나눠서 생각하면 해결할 수 있다.