//boj2512번_예산_이분 탐색

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	int M;
	cin >> M;

	sort(v.begin(), v.end());

	int start = 0;
	int end = v.back();
	int result = 999999;

	while (start <= end) {
		int sum = 0;
		int mid = (start + end) / 2;

		for (int i = 0; i < N; i++) {
			sum += min(v[i], mid);
		}

		if (sum <= M) {
			result = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << result;
}
//이분 탐색 문제.
//이분 탐색을 이용해서 값을 조금씩 늘려가며 전체 국가예산을 넘지않게 맞추는 것이 문제의 핵심이다.
//모든 요청이 배정될 수 있는 경우에 요청한 금액을 그대로 배정하고, 불가능한 경우에는 상한액을 계산하여 그 이상인 예산요청에는
//모두 상한액을 배정해야되기 때문에 예산요청(v[i]값)과 이분탐색을 통해 선정한 상한액(mid)를 비교해가며 전체 국가예산을 맞추면 해결할 수 있다.