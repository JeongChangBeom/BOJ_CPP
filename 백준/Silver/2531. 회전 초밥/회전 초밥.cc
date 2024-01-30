//boj2531번_회전 초밥_슬라이딩 윈도우

#include<iostream>
#include<vector>

using namespace std;

bool check[30001];

int main() {
	int N, d, k, c;
	cin >> N >> d >> k >> c;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	int result = -999;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 30001; j++) {
			check[j] = false;
		}

		int overlap = 0;
		bool coupon = true;
		for (int j = i; j < i + k; j++) {
			if (check[v[j % N]] == true) {
				overlap++;
			}
			else {
				check[v[j % N]] = true;
			}

			if (v[j % N] == c) {
				coupon = false;
			}
		}
		if (coupon) {
			result = max(result, k - overlap + 1);
		}
		else {
			result = max(result, k - overlap);
		}
	}
	cout << result;
}
//슬라이딩 윈도우를 이용한 문제.
//슬라이딩 윈도우란 동일한 크기의 윈도우가 이동하면서 윈도우안의 값을 이용하는 알고리즘이다.
//이 문제에선 연속해서 먹는 접시의 수(k)가 윈도우라고 할 수 있다.
//슬라이딩 윈도우를 통해 연속해서 초밥을 먹을 수 있는 경우의 수 중 가장 많은 종류의 초밥을 먹는 경우의 수를 찾았다.
//거기에 쿠폰과 중복된 초밥을 먹는 경우의 수가 아닌경우 +1을 해주었다.