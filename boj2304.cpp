//boj2304번_창고 다각형_브루트포스

#include<iostream>
#include<algorithm>

using namespace std;

int arr[1001];

int main() {
	int N;
	cin >> N;

	int maxH = 0;
	int maxH_L = 0;
	int maxL = 0;
	int minL = 9999;

	for (int i = 0; i < N; i++) {
		int L, H;
		cin >> L >> H;

		arr[L] = H;

		if (maxH < H) {
			maxH_L = L;
		}

		maxH = max(maxH, H);
		maxL = max(maxL, L);
		minL = min(minL, L);
	}

	int result = 0;
	int curH = 0;

	for (int i = minL; i < maxH_L; i++) {
		if (arr[i] != 0) {
			if (curH < arr[i]) {
				curH = arr[i];
			}
		}
		result += curH;
	}

	curH = 0;

	for (int i = maxL; i >= maxH_L; i--) {
		if (arr[i] != 0) {
			if (curH < arr[i]) {
				curH = arr[i];
			}
		}
		result += curH;
	}

	cout << result;
}
//브루트포스 문제라는데 거의 구현 문제처럼 해결했다.
//처음 입력값을 받을때 양쪽 끝 지점(minL, maxL)과 가장 높은 기둥의 높이(maxH)와 위치(maxH_L)을 저장해놓고
//가장 긴 기둥의 왼쪽과 오른쪽의 크기를 더해주는 식으로 해결했다.