//boj1026번_보물_그리디알고리즘, 정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int x, int y) {
	return y < x;
}

int main() {
	int N;
	cin >> N;

	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v1.push_back(x);
	}

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v2.push_back(x);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), compare);

	int result = 0;

	for (int i = 0; i < v1.size(); i++) {
		result += v1[i] * v2[i];
	}

	cout << result;
}
//첫번째 벡터를 오름차순으로 정렬하고, 두번째 벡터를 내림차순으로 정렬한다음
//순차적으로 곱하면 최솟값이 나온다. 문제를 읽어보면 두번째 벡터에 있는 수를
//재배열(정렬)하면 안된다고 나와있는데 위와 같이 풀어도 정답처리가 된다.
//문제에 오류가 있거나 내가 이해 못한 부분이 있는 것 같다.