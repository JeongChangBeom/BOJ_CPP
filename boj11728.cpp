//boj11728_배열 합치기_정렬

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector <int> result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		result.push_back(x);
	}

	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		result.push_back(x);
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}	
//투포인터로 풀 수도 있는 문제지만 입출력가속을 넣어보니 시간초과가 나지않아 간단하게 정렬로 풀었다.