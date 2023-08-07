//boj1448번_삼각형 만들기_정렬, 그리디 알고리즘

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int x, int y) {
	return x > y;
}

int main() {
	int N;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end(), compare);

	int result = -99;

	for (int i = 0; i <= N - 3; i++) {
		if (v[i] < v[i + 1] + v[i + 2]) {
			result = v[i] + v[i + 1] + v[i + 2];
			break;
		}
	}

	if (result == -99) {
		cout << "-1";
	}
	else {
		cout << result;
	}
}
//정렬을 이용한 문제. 삼각형이 되기 위한 조건은 가장 긴 변의 길이가 나머지 두변의 길이의 합보다 작아야된다.