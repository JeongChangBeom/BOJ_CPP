//boj2805번_나무 자르기_이분 탐색

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	long start = 0;
	long end = *max_element(v.begin(), v.end());

	long result = 0;

	while (start <= end) {
		long length = 0;

		long mid = (start + end) / 2;

		for (int i = 0; i < v.size(); i++) {
			if (v[i] < mid) {
				continue;
			}
			else {
				length += v[i] - mid;
			}
		}

		if (length >= M) {
			start = mid + 1;
			result = max(result, mid);
		}
		if (length > M) {
			start = mid + 1;
		}
		else if (length < M) {
			end = mid - 1;
		}
	}
	cout << result;
}
//최근에 풀었던 랜선 자르기와 유사한 문제.
//인터넷에 돌아다니는 모든 테스트 케이스가 통과되는데 틀렸다고 나와서 틀린 부분을 정말 찾기 힘들었는데
//M의 범위가 20억까지여서 long타입 변수를 사용해서 해결할 수 있었다.