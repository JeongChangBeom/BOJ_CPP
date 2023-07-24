//boj1072번_게임_이분탐색

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	long long X, Y, Z;
	int result = -1;
	cin >> X >> Y;

	Z = (Y * 100) / X;

	if (Z >= 99) {
		cout << result << '\n';
		return 0;
	}

	int start = 0;
	int end = 1000000000;

	while (start <= end) {
		int mid = (start + end) / 2;
		int tmp = ((Y + mid) * 100) / (X + mid);

		if (Z < tmp) {
			result = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	
	cout << result;
}
//이분탐색을 이용해 해결한 문제. 일반적으로 1씩 더해가며 탐색을 반복하게 되면
//X의 최대값이 10억이므로 시간초과가 나는 점을 유의해야한다.