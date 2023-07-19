//boj2217번_로프_정렬

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(int x, int y) {
	return x > y;
}

int main() {
	int N;
	cin >> N;
	
	vector<int> v;

	for (int i = 0; i < N; i++) {
		int kg;
		cin >> kg;
		v.push_back(kg);
	}

	sort(v.begin(), v.end(), compare);

	int result = 0;

	for (int i = 1; i <= v.size(); i++) {
		int tmp = v[i - 1] * i;
		if (result < tmp) {
			result = tmp;
		}
	}

	cout << result;
}
//정렬을 이용해서 해결한 문제. 로프에 걸리는 중량을 나눌수 있다는 점을 이용해서 내림차순으로 정렬한 후
//하중이 가장 큰 로프1개만 사용할 때, 하중이 2번째로 큰 로프 2개만 사용할 때......이런식으로 구해서 최대값을 구했다. 