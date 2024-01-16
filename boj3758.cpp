//boj3758번_KCPC_정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct team {
	int id;
	int count;
	int score;
	int time;
};

team tm[101];
int arr[101][101];

bool compare(team x, team y) {
	if (x.score == y.score) {
		if (x.count == y.count) {
			return x.time < y.time;
		}
		else {
			return x.count < y.count;
		}
	}
	else {
		return x.score > y.score;
	}
}

int main() {
	int T;
	cin >> T;

	for (int test = 0; test < T; test++) {
		for (int i = 0; i < 101; i++) {
			tm[i].id = 0;
			tm[i].count = 0;
			tm[i].score = 0;
			tm[i].time = 0;
		}

		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				arr[i][j] = 0;
			}
		}

		int n, k, t, m;
		cin >> n >> k >> t >> m;

		for (int i = 0; i < n; i++) {
			tm[i].id = i + 1;
		}

		for (int i = 0; i < m; i++) {
			int d, num, s;
			cin >> d >> num >> s;

			arr[d][num] = max(arr[d][num], s);
			tm[d - 1].count++;
			tm[d - 1].time = i;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				tm[i - 1].score += arr[i][j];
			}
		}

		sort(tm, tm + n, compare);

		int result = 0;

		for (int i = 0; i < n; i++) {
			if (tm[i].id == t) {
				result = i + 1;
			}
		}
		cout << result << '\n';
	}
}
//정렬문제. 구조체를 이용해서 해결했다.
//algorithm헤더 파일에 있는 sort함수를 이용하기 위해 조건에 맞는 compare함수를 만들었다.
//정렬 문제의 핵심은 문제에서 주어진 정렬 조건을 이해하는 것이다.
//1.총점이 높으면 순위가 높다. 2.총점이 같으면 풀이를 적게 제출한 팀의 순위가 높다.
//3. 총점,풀이 제출 횟수가 같을 경우 마지막으로 제출한 시간이 빠를 수록 순위가 높다.
//위 세가지 조건으로 정렬할 수 있는 compare함수를 만들면 해결할 수 있다.