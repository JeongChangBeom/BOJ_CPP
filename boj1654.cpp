//boj1654번_랜선 자르기_이분탐색

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int K, N;
	cin >> K >> N;

	vector<int> v;

	for (int i = 0; i < K; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int start = 1;
	unsigned int end = *max_element(v.begin(), v.end());
	unsigned int mid;
	unsigned int result = 0;

	while (start <= end) {
		unsigned key = 0;

		mid = (start + end) / 2;

		for (int i = 0; i < v.size(); i++) {
			key += v[i] / mid;
		}

		if (key >= N) {
			start = mid + 1;
			result = max(result, mid);
		}
		else {
			end = mid - 1;
		}
	}

	cout << result;
}
//이분탐색으로 해결할 수 있는 문제. 랜선의 길이는 2^31-1보다 작거나 같은 자연수라는 조건을 놓쳐
//틀렸었는데 unsigned int형으로 바꿔서 해결했다.