//boj2012번_등수 매기기_그리디 알고리즘, 정렬

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	long long result = 0;

	for (int i = 0; i < N; i++) {
		result += abs((i + 1) - v[i]);
	}

	cout << result;
}
//정렬 문제
//sort를 이용해서 정렬후 1~N등을 부여해서 값을 더해주는 식으로 풀었다.