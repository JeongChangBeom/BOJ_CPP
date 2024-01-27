//boj1166_선물_이분 탐색

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int N, L, W, H;

	cin >> N >> L >> W >> H;

	double start = 0;
	double end = max(L,max(W,H));

	for (int i = 0; i < 10000; i++) {
		double mid = (start + end) / 2;
		if (((long long)(L / mid)) * ((long long)(W / mid)) * ((long long)(H / mid)) >= N) {
			start = mid;
		}
		else {
			end = mid;
		}
	}

	cout << fixed;
	cout.precision(10);

	cout << start;
}
//이분탐색을 이용한 문제.
//이분탐색을 이용해서 조건식(가로/mid * 세로/mid * 높이/mid)이 N보다 작을 경우 길이를 줄이기 위해 start = mid를 해주고
//반대의 경우 늘리기 위해 end = mid를 해준다.
//추가로 출력까지 신경써야되는 문제. 소수점 10번째자리까지 나타내면서 빈칸은 0으로 채워줘야했다.