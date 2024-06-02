//boj2343_기타 레슨_이분 탐색

#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int start = 0;
	int end = 0;
	int result = 0;

	cin >> N >> M;

	vector<int> blueray;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		blueray.push_back(num);

		start = max(num, start);
		end += num;
	}

	while (start <= end) {
		int mid = (start + end) / 2;

		int sum = 0;
		int count = 0;

		for (int i = 0; i < N; i++) {
			sum += blueray[i];
			if (mid < sum) {
				i--;
				sum = 0;
				count++;
			}
		}

		if (count >= M) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
			result = mid;
		}
	}
	cout << result;

	return 0;
}