//boj14719번_빗물_구현

#include<iostream>

using namespace std;

int width[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int h, w;
	cin >> h >> w;

	for (int i = 0; i < w; i++) {
		cin >> width[i];
	}

	int result = 0;

	for (int i = 1; i < w - 1; i++) {
		int left = width[i];
		int right = width[i];

		for (int j = 0; j < i; j++) {
			left = max(left, width[j]);
		}
		for (int j = i; j < w; j++) {
			right = max(right, width[j]);
		}

		result += min(left, right) - width[i];
	}

	cout << result;
}
//구현문제.
//가장 왼쪽과 가장 오른쪽은 물이 고일 수 없으므로 1 ~ w-1까지만 확인하면된다.
//현재 인덱스를 기준으로 왼쪽과 오른쪽 높이의 최대값을 구하고, 그중에 작은 값을 구한다.(높은 값으로 하면 넘치기 때문)
//구한 값에서 현재 인덱스의 높이를 빼면 현재 인덱스에 물이 얼마나 고인지 알 수 있음.
//그 값들을 전부 더하면 총 물이 얼마나 고인지 알 수 있음.
