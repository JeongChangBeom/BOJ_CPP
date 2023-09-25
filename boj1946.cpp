//boj1946번_신입 사원_그리디 알고리즘, 정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		vector<pair<int, int>> v;

		for (int i = 0; i < N; i++) {
			int test1, test2;
			cin >> test1 >> test2;

			v.push_back({ test1, test2 });
		}

		sort(v.begin(), v.end());

		int result = 0;
		int i = 0;

		for (int j = 1; j < N; j++) {
			if (v[i].second > v[j].second) {
				result++;
				i = j;
			}
		}
		cout << result + 1 << '\n';
	}
}
//정렬을 사용한 그리디 알고리즘 문제.
//먼저 서류 점수(test1)로 정렬을 한 후, 서류 점수 1등부터 다음 등수의 면접순위와 비교하는 식으로 해결했다.