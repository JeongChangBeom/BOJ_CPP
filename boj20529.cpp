//boj20529번_가장 가까운 세 사람의 심리적 거리_비둘기집 원리

#include<iostream>
#include<vector>

using namespace std;

int distance(string x, string y, string z) {
	int dis = 0;
	for (int i = 0; i < 4; i++) {
		if (x[i] != y[i]) {
			dis++;
		}
		if (y[i] != z[i]) {
			dis++;
		}
		if (z[i] != x[i]) {
			dis++;
		}
	}
	return dis;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		vector<string> v;

		for (int i = 0; i < N; i++) {
			string mbti;
			cin >> mbti;
			v.push_back(mbti);
		}

		if (N > 32) {
			cout << '0' << '\n';
		}
		else {
			int result = 999999;

			for (int i = 0; i < N - 2; i++) {
				for (int j = i + 1; j < N - 1; j++) {
					for (int k = j + 1; k < N; k++) {
						result = min(result, distance(v[i], v[j], v[k]));
					}
				}
			}
			cout << result << '\n';
		}
	}
}
//비둘기집 원리를 사용하여 시간초과를 피하는 것이 핵심인 문제. mbti는 총 16가지 이므로 입력을 32개 넘게 받으면 무조건
//가장 가까운 세사람의 거리가 0이 된다는 점을 이용했다.