//boj20437번_문자열 게임 2

#include<iostream>
#include<string>

using namespace std;

int arr[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string W;
		cin >> W;

		int K;
		cin >> K;

		for (int i = 0; i < W.size(); i++) {
			arr[W[i] - 'a']++;
		}

		int min = 99999;
		int max = 0;

		for (int i = 0; i < W.size(); i++) {
			if (arr[W[i] - 'a'] < K) {
				continue;
			}

			int cnt = 0;

			for (int j = i; j < W.size(); j++) {
				if (W[i] == W[j]) {
					cnt++;
				}
				if (cnt == K) {
					min = std::min(min, j - i + 1);
					max = std::max(max, j - i + 1);
					break;
;				}
			}
		}

		if (min ==99999 || max ==0) {
			cout << "-1" << '\n';
		}
		else {
			cout << min << ' ' << max << '\n';
		}
	}
}